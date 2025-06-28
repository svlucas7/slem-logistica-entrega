#include <stdio.h>
#include <stdlib.h>
#include "locais.h"
#include "veiculos.h"
#include "pedidos.h"
#include "rota.h"
#include "backup.h"

void exibirMenu() {
    printf("\n==== Sistema de Logística de Entrega de Mercadorias (SLEM) ===="\n");
    printf("1. Cadastro de Locais\n");
    printf("2. Cadastro de Veículos\n");
    printf("3. Cadastro de Pedidos\n");
    printf("4. Calcular e Exibir Rota de Entrega\n");
    printf("5. Backup de dados\n");
    printf("6. Restaurar dados\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    ListaLocais locais;
    ListaVeiculos veiculos;
    ListaPedidos pedidos;
    inicializarListaLocais(&locais);
    inicializarListaVeiculos(&veiculos);
    inicializarListaPedidos(&pedidos);

    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                // CRUD Locais
                break;
            case 2:
                // CRUD Veículos
                break;
            case 3:
                // CRUD Pedidos
                break;
            case 4:
                // Calcular e exibir rota
                break;
            case 5:
                // Backup
                break;
            case 6:
                // Restaurar
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    destruirListaLocais(&locais);
    destruirListaVeiculos(&veiculos);
    destruirListaPedidos(&pedidos);
    return 0;
}
