#include <stdio.h>
#include <math.h>
#include "rota.h"

// Calcula a distância euclidiana entre dois locais
float calcularDistancia(Local a, Local b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

// Encontra o índice do veículo disponível mais próximo do local de origem
int encontrarVeiculoMaisProximo(ListaVeiculos* veiculos, ListaLocais* locais, int origem) {
    int idx = -1;
    float menorDist = -1;
    for (int i = 0; i < veiculos->quantidade; i++) {
        if (veiculos->veiculos[i].status == DISPONIVEL) {
            float dist = calcularDistancia(locais->locais[veiculos->veiculos[i].localAtual], locais->locais[origem]);
            if (menorDist < 0 || dist < menorDist) {
                menorDist = dist;
                idx = i;
            }
        }
    }
    return idx;
}

// Exibe a rota de entrega para um pedido, selecionando o veículo mais próximo
void exibirRotaEntrega(ListaVeiculos* veiculos, ListaLocais* locais, ListaPedidos* pedidos, int idPedido) {
    int idxPedido = buscarPedidoPorId(pedidos, idPedido);
    if (idxPedido == -1) {
        printf("Pedido não encontrado!\n");
        return;
    }
    Pedido* pedido = &pedidos->pedidos[idxPedido];
    int idxVeiculo = encontrarVeiculoMaisProximo(veiculos, locais, pedido->origem);
    if (idxVeiculo == -1) {
        printf("Nenhum veículo disponível!\n");
        return;
    }
    Veiculo* veiculo = &veiculos->veiculos[idxVeiculo];
    float dist = calcularDistancia(locais->locais[veiculo->localAtual], locais->locais[pedido->origem]) +
                 calcularDistancia(locais->locais[pedido->origem], locais->locais[pedido->destino]);
    printf("\nRota de Entrega:\n");
    printf("Veículo: %s (%s)\n", veiculo->placa, veiculo->modelo);
    printf("Origem: %s\n", locais->locais[pedido->origem].nome);
    printf("Destino: %s\n", locais->locais[pedido->destino].nome);
    printf("Distância total: %.2f\n", dist);
    // Simulação da entrega
    veiculo->status = OCUPADO;
    veiculo->localAtual = pedido->destino;
    veiculo->status = DISPONIVEL;
}
