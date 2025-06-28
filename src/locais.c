#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locais.h"

#define CAPACIDADE_INICIAL 10

void inicializarListaLocais(ListaLocais* lista) {
    lista->quantidade = 0;
    lista->capacidade = CAPACIDADE_INICIAL;
    lista->locais = (Local*)malloc(lista->capacidade * sizeof(Local));
}

void destruirListaLocais(ListaLocais* lista) {
    free(lista->locais);
    lista->locais = NULL;
    lista->quantidade = 0;
    lista->capacidade = 0;
}

int adicionarLocal(ListaLocais* lista, Local local) {
    if (buscarLocalPorNome(lista, local.nome) != -1) return 0; // já existe
    if (lista->quantidade == lista->capacidade) {
        lista->capacidade *= 2;
        lista->locais = (Local*)realloc(lista->locais, lista->capacidade * sizeof(Local));
    }
    lista->locais[lista->quantidade++] = local;
    return 1;
}

int buscarLocalPorNome(ListaLocais* lista, const char* nome) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (strcmp(lista->locais[i].nome, nome) == 0) return i;
    }
    return -1;
}

int atualizarLocal(ListaLocais* lista, const char* nome, Local novoLocal) {
    int idx = buscarLocalPorNome(lista, nome);
    if (idx == -1) return 0;
    lista->locais[idx] = novoLocal;
    return 1;
}

int removerLocal(ListaLocais* lista, const char* nome) {
    int idx = buscarLocalPorNome(lista, nome);
    if (idx == -1) return 0;
    for (int i = idx; i < lista->quantidade - 1; i++) {
        lista->locais[i] = lista->locais[i + 1];
    }
    lista->quantidade--;
    return 1;
}

void listarLocais(ListaLocais* lista) {
    printf("\nLocais cadastrados:\n");
    for (int i = 0; i < lista->quantidade; i++) {
        printf("%d. %s (%.2f, %.2f)\n", i + 1, lista->locais[i].nome, lista->locais[i].x, lista->locais[i].y);
    }
}
