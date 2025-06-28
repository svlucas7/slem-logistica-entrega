#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculos.h"

#define CAPACIDADE_INICIAL 10

void inicializarListaVeiculos(ListaVeiculos* lista) {
    lista->quantidade = 0;
    lista->capacidade = CAPACIDADE_INICIAL;
    lista->veiculos = (Veiculo*)malloc(lista->capacidade * sizeof(Veiculo));
}

void destruirListaVeiculos(ListaVeiculos* lista) {
    free(lista->veiculos);
    lista->veiculos = NULL;
    lista->quantidade = 0;
    lista->capacidade = 0;
}

int adicionarVeiculo(ListaVeiculos* lista, Veiculo veiculo) {
    if (buscarVeiculoPorPlaca(lista, veiculo.placa) != -1) return 0; // já existe
    if (lista->quantidade == lista->capacidade) {
        lista->capacidade *= 2;
        lista->veiculos = (Veiculo*)realloc(lista->veiculos, lista->capacidade * sizeof(Veiculo));
    }
    lista->veiculos[lista->quantidade++] = veiculo;
    return 1;
}

int buscarVeiculoPorPlaca(ListaVeiculos* lista, const char* placa) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (strcmp(lista->veiculos[i].placa, placa) == 0) return i;
    }
    return -1;
}

int atualizarVeiculo(ListaVeiculos* lista, const char* placa, Veiculo novoVeiculo) {
    int idx = buscarVeiculoPorPlaca(lista, placa);
    if (idx == -1) return 0;
    lista->veiculos[idx] = novoVeiculo;
    return 1;
}

int removerVeiculo(ListaVeiculos* lista, const char* placa) {
    int idx = buscarVeiculoPorPlaca(lista, placa);
    if (idx == -1) return 0;
    for (int i = idx; i < lista->quantidade - 1; i++) {
        lista->veiculos[i] = lista->veiculos[i + 1];
    }
    lista->quantidade--;
    return 1;
}

void listarVeiculos(ListaVeiculos* lista) {
    printf("\nVeículos cadastrados:\n");
    for (int i = 0; i < lista->quantidade; i++) {
        printf("%d. %s - %s [%s] Local: %d\n", i + 1, lista->veiculos[i].placa, lista->veiculos[i].modelo,
            lista->veiculos[i].status == DISPONIVEL ? "Disponível" : "Ocupado", lista->veiculos[i].localAtual);
    }
}
