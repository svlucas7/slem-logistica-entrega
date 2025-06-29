#ifndef BACKUP_H
#define BACKUP_H

#include "locais.h"
#include "veiculos.h"
#include "pedidos.h"

// Salva os dados das listas em arquivos binários
int salvarBackup(const ListaLocais* locais, const ListaVeiculos* veiculos, const ListaPedidos* pedidos);
// Restaura os dados das listas a partir dos arquivos binários
int restaurarBackup(ListaLocais* locais, ListaVeiculos* veiculos, ListaPedidos* pedidos);

#endif // BACKUP_H
