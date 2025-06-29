#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculos.h"

#define CAPACIDADE_INICIAL 10

// Inicializa a lista dinâmica de veículos, alocando memória inicial
void inicializarListaVeiculos(ListaVeiculos* lista) {
    lista->quantidade = 0;
    lista->capacidade = CAPACIDADE_INICIAL;
    lista->veiculos = (Veiculo*)malloc(lista->capacidade * sizeof(Veiculo));
}

// Libera toda a memória alocada para a lista de veículos
void destruirListaVeiculos(ListaVeiculos* lista) {
    free(lista->veiculos);
    lista->veiculos = NULL;
    lista->quantidade = 0;
    lista->capacidade = 0;
}

// Adiciona um novo veículo ao vetor, se não existir outro com a mesma placa
// Retorna 1 se sucesso, 0 se já existe
int adicionarVeiculo(ListaVeiculos* lista, Veiculo veiculo) {
    if (buscarVeiculoPorPlaca(lista, veiculo.placa) != -1) return 0; // já existe
    if (lista->quantidade == lista->capacidade) {
        // Dobra a capacidade do vetor se necessário
        lista->capacidade *= 2;
        lista->veiculos = (Veiculo*)realloc(lista->veiculos, lista->capacidade * sizeof(Veiculo));
    }
    lista->veiculos[lista->quantidade++] = veiculo;
    return 1;
}

// Busca o índice de um veículo pela placa. Retorna -1 se não encontrado
int buscarVeiculoPorPlaca(ListaVeiculos* lista, const char* placa) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (strcmp(lista->veiculos[i].placa, placa) == 0) return i;
    }
    return -1;
}

// Atualiza os dados de um veículo identificado pela placa
int atualizarVeiculo(ListaVeiculos* lista, const char* placa, Veiculo novoVeiculo) {
    int idx = buscarVeiculoPorPlaca(lista, placa);
    if (idx == -1) return 0;
    lista->veiculos[idx] = novoVeiculo;
    return 1;
}

// Remove um veículo do vetor pela placa, deslocando os elementos
int removerVeiculo(ListaVeiculos* lista, const char* placa) {
    int idx = buscarVeiculoPorPlaca(lista, placa);
    if (idx == -1) return 0;
    for (int i = idx; i < lista->quantidade - 1; i++) {
        lista->veiculos[i] = lista->veiculos[i + 1];
    }
    lista->quantidade--;
    return 1;
}

// Exibe todos os veículos cadastrados, mostrando placa, modelo, status e local
void listarVeiculos(ListaVeiculos* lista) {
    printf("\nVeículos cadastrados:\n");
    for (int i = 0; i < lista->quantidade; i++) {
        printf("%d. %s - %s [%s] Local: %d\n", i + 1, lista->veiculos[i].placa, lista->veiculos[i].modelo,
            lista->veiculos[i].status == DISPONIVEL ? "Disponível" : "Ocupado", lista->veiculos[i].localAtual);
    }
}
