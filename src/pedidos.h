#ifndef PEDIDOS_H
#define PEDIDOS_H

typedef struct {
    int id; // identificador único
    int origem;  // índice do Local
    int destino; // índice do Local
    float peso;
} Pedido;

typedef struct {
    Pedido* pedidos;
    int quantidade;
    int capacidade;
} ListaPedidos;

void inicializarListaPedidos(ListaPedidos* lista);
void destruirListaPedidos(ListaPedidos* lista);
int adicionarPedido(ListaPedidos* lista, Pedido pedido);
int buscarPedidoPorId(ListaPedidos* lista, int id);
int atualizarPedido(ListaPedidos* lista, int id, Pedido novoPedido);
int removerPedido(ListaPedidos* lista, int id);
void listarPedidos(ListaPedidos* lista);

#endif // PEDIDOS_H
