#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locais.h"

#define CAPACIDADE_INICIAL 10

// Inicializa a lista dinâmica de locais, alocando memória inicial
void inicializarListaLocais(ListaLocais* lista) {
    lista->quantidade = 0;
    lista->capacidade = CAPACIDADE_INICIAL;
    lista->locais = (Local*)malloc(lista->capacidade * sizeof(Local));
}

// Libera toda a memória alocada para a lista de locais
void destruirListaLocais(ListaLocais* lista) {
    free(lista->locais);
    lista->locais = NULL;
    lista->quantidade = 0;
    lista->capacidade = 0;
}

// Adiciona um novo local ao vetor, se não existir outro com o mesmo nome
// Retorna 1 se sucesso, 0 se já existe
int adicionarLocal(ListaLocais* lista, Local local) {
    if (buscarLocalPorNome(lista, local.nome) != -1) return 0; // já existe
    if (lista->quantidade == lista->capacidade) {
        // Dobra a capacidade do vetor se necessário
        lista->capacidade *= 2;
        lista->locais = (Local*)realloc(lista->locais, lista->capacidade * sizeof(Local));
    }
    lista->locais[lista->quantidade++] = local;
    return 1;
}

// Busca o índice de um local pelo nome. Retorna -1 se não encontrado
int buscarLocalPorNome(ListaLocais* lista, const char* nome) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (strcmp(lista->locais[i].nome, nome) == 0) return i;
    }
    return -1;
}

// Atualiza os dados de um local identificado pelo nome
int atualizarLocal(ListaLocais* lista, const char* nome, Local novoLocal) {
    int idx = buscarLocalPorNome(lista, nome);
    if (idx == -1) return 0;
    lista->locais[idx] = novoLocal;
    return 1;
}

// Remove um local do vetor pelo nome, deslocando os elementos
int removerLocal(ListaLocais* lista, const char* nome) {
    int idx = buscarLocalPorNome(lista, nome);
    if (idx == -1) return 0;
    for (int i = idx; i < lista->quantidade - 1; i++) {
        lista->locais[i] = lista->locais[i + 1];
    }
    lista->quantidade--;
    return 1;
}

// Exibe todos os locais cadastrados, mostrando nome e coordenadas
void listarLocais(ListaLocais* lista) {
    printf("\nLocais cadastrados:\n");
    for (int i = 0; i < lista->quantidade; i++) {
        printf("%d. %s (%.2f, %.2f)\n", i + 1, lista->locais[i].nome, lista->locais[i].x, lista->locais[i].y);
    }
}
