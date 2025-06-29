#ifndef ROTA_H
#define ROTA_H

#include "locais.h"
#include "veiculos.h"
#include "pedidos.h"

// Calcula a distância euclidiana entre dois locais
float calcularDistancia(Local a, Local b);

// Encontra o índice do veículo disponível mais próximo do local de origem
int encontrarVeiculoMaisProximo(ListaVeiculos* veiculos, ListaLocais* locais, int origem);

// Exibe a rota de entrega para um pedido, selecionando o veículo mais próximo
void exibirRotaEntrega(ListaVeiculos* veiculos, ListaLocais* locais, ListaPedidos* pedidos, int idPedido);

#endif // ROTA_H
