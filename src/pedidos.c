#include <stdio.h>
#include <stdlib.h>
#include "pedidos.h"

#define CAPACIDADE_INICIAL 10

// Inicializa a lista de pedidos com capacidade inicial
void inicializarListaPedidos(ListaPedidos* lista) {
    lista->quantidade = 0;
    lista->capacidade = CAPACIDADE_INICIAL;
    lista->pedidos = (Pedido*)malloc(lista->capacidade * sizeof(Pedido));
}

// Libera a memória alocada para a lista de pedidos
void destruirListaPedidos(ListaPedidos* lista) {
    free(lista->pedidos);
    lista->pedidos = NULL;
    lista->quantidade = 0;
    lista->capacidade = 0;
}

// Adiciona um novo pedido à lista, se não existir outro com o mesmo id
int adicionarPedido(ListaPedidos* lista, Pedido pedido) {
    if (buscarPedidoPorId(lista, pedido.id) != -1) return 0; // já existe
    if (lista->quantidade == lista->capacidade) {
        lista->capacidade *= 2;
        lista->pedidos = (Pedido*)realloc(lista->pedidos, lista->capacidade * sizeof(Pedido));
    }
    lista->pedidos[lista->quantidade++] = pedido;
    return 1;
}

// Busca o índice de um pedido pelo id. Retorna -1 se não encontrado
int buscarPedidoPorId(ListaPedidos* lista, int id) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (lista->pedidos[i].id == id) return i;
    }
    return -1;
}

// Atualiza os dados de um pedido identificado pelo id
int atualizarPedido(ListaPedidos* lista, int id, Pedido novoPedido) {
    int idx = buscarPedidoPorId(lista, id);
    if (idx == -1) return 0;
    lista->pedidos[idx] = novoPedido;
    return 1;
}

// Remove um pedido da lista pelo id
int removerPedido(ListaPedidos* lista, int id) {
    int idx = buscarPedidoPorId(lista, id);
    if (idx == -1) return 0;
    for (int i = idx; i < lista->quantidade - 1; i++) {
        lista->pedidos[i] = lista->pedidos[i + 1];
    }
    lista->quantidade--;
    return 1;
}

// Exibe todos os pedidos cadastrados
void listarPedidos(ListaPedidos* lista) {
    printf("\nPedidos cadastrados:\n");
    for (int i = 0; i < lista->quantidade; i++) {
        printf("%d. ID: %d | Origem: %d | Destino: %d | Peso: %.2f kg\n", i + 1, lista->pedidos[i].id, lista->pedidos[i].origem, lista->pedidos[i].destino, lista->pedidos[i].peso);
    }
}
