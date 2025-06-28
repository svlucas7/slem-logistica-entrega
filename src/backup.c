#include <stdio.h>
#include "backup.h"

int salvarBackup(const ListaLocais* locais, const ListaVeiculos* veiculos, const ListaPedidos* pedidos) {
    FILE* f;
    f = fopen("data/locais.bin", "wb");
    if (!f) return 0;
    fwrite(&locais->quantidade, sizeof(int), 1, f);
    fwrite(locais->locais, sizeof(Local), locais->quantidade, f);
    fclose(f);

    f = fopen("data/veiculos.bin", "wb");
    if (!f) return 0;
    fwrite(&veiculos->quantidade, sizeof(int), 1, f);
    fwrite(veiculos->veiculos, sizeof(Veiculo), veiculos->quantidade, f);
    fclose(f);

    f = fopen("data/pedidos.bin", "wb");
    if (!f) return 0;
    fwrite(&pedidos->quantidade, sizeof(int), 1, f);
    fwrite(pedidos->pedidos, sizeof(Pedido), pedidos->quantidade, f);
    fclose(f);
    return 1;
}

int restaurarBackup(ListaLocais* locais, ListaVeiculos* veiculos, ListaPedidos* pedidos) {
    FILE* f;
    int qtd;
    f = fopen("data/locais.bin", "rb");
    if (!f) return 0;
    fread(&qtd, sizeof(int), 1, f);
    destruirListaLocais(locais);
    inicializarListaLocais(locais);
    for (int i = 0; i < qtd; i++) {
        Local l;
        fread(&l, sizeof(Local), 1, f);
        adicionarLocal(locais, l);
    }
    fclose(f);

    f = fopen("data/veiculos.bin", "rb");
    if (!f) return 0;
    fread(&qtd, sizeof(int), 1, f);
    destruirListaVeiculos(veiculos);
    inicializarListaVeiculos(veiculos);
    for (int i = 0; i < qtd; i++) {
        Veiculo v;
        fread(&v, sizeof(Veiculo), 1, f);
        adicionarVeiculo(veiculos, v);
    }
    fclose(f);

    f = fopen("data/pedidos.bin", "rb");
    if (!f) return 0;
    fread(&qtd, sizeof(int), 1, f);
    destruirListaPedidos(pedidos);
    inicializarListaPedidos(pedidos);
    for (int i = 0; i < qtd; i++) {
        Pedido p;
        fread(&p, sizeof(Pedido), 1, f);
        adicionarPedido(pedidos, p);
    }
    fclose(f);
    return 1;
}
