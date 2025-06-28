#ifndef BACKUP_H
#define BACKUP_H

#include "locais.h"
#include "veiculos.h"
#include "pedidos.h"

int salvarBackup(const ListaLocais* locais, const ListaVeiculos* veiculos, const ListaPedidos* pedidos);
int restaurarBackup(ListaLocais* locais, ListaVeiculos* veiculos, ListaPedidos* pedidos);

#endif // BACKUP_H
