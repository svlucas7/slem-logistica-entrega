#ifndef PEDIDOS_H
#define PEDIDOS_H

// Estrutura que representa um pedido (id, origem, destino, peso)
typedef struct {
    int id; // identificador único
    int origem;  // índice do Local
    int destino; // índice do Local
    float peso;
} Pedido;

// Estrutura que representa uma lista dinâmica de pedidos
typedef struct {
    Pedido* pedidos;
    int quantidade;
    int capacidade;
} ListaPedidos;

// Inicializa a lista de pedidos
void inicializarListaPedidos(ListaPedidos* lista);
// Libera a memória da lista de pedidos
void destruirListaPedidos(ListaPedidos* lista);
// Adiciona um pedido à lista
int adicionarPedido(ListaPedidos* lista, Pedido pedido);
// Busca o índice de um pedido pelo id
int buscarPedidoPorId(ListaPedidos* lista, int id);
// Atualiza um pedido identificado pelo id
int atualizarPedido(ListaPedidos* lista, int id, Pedido novoPedido);
// Remove um pedido pelo id
int removerPedido(ListaPedidos* lista, int id);
// Lista todos os pedidos cadastrados
void listarPedidos(ListaPedidos* lista);

#endif // PEDIDOS_H
