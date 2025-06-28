#ifndef ROTA_H
#define ROTA_H

#include "locais.h"
#include "veiculos.h"
#include "pedidos.h"

float calcularDistancia(Local a, Local b);
int encontrarVeiculoMaisProximo(ListaVeiculos* veiculos, ListaLocais* locais, int origem);
void exibirRotaEntrega(ListaVeiculos* veiculos, ListaLocais* locais, ListaPedidos* pedidos, int idPedido);

#endif // ROTA_H
