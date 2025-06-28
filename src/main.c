#include <stdio.h>
#include <stdlib.h>
#include "locais.h"
#include "veiculos.h"
#include "pedidos.h"
#include "rota.h"
#include "backup.h"

void exibirMenu() {
    printf("\n==== Sistema de Logística de Entrega de Mercadorias (SLEM) ====\n");
    printf("1. Cadastro de Locais\n");
    printf("2. Cadastro de Veículos\n");
    printf("3. Cadastro de Pedidos\n");
    printf("4. Calcular e Exibir Rota de Entrega\n");
    printf("5. Backup de dados\n");
    printf("6. Restaurar dados\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

void submenuVeiculos(ListaVeiculos* veiculos) {
    int opcao;
    do {
        printf("\n--- Cadastro de Veículos ---\n");
        printf("1. Adicionar Veículo\n");
        printf("2. Listar Veículos\n");
        printf("3. Atualizar Veículo\n");
        printf("4. Remover Veículo\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa buffer
        if (opcao == 1) {
            Veiculo v;
            printf("Placa: ");
            fgets(v.placa, MAX_PLACA, stdin);
            v.placa[strcspn(v.placa, "\n")] = 0;
            printf("Modelo: ");
            fgets(v.modelo, MAX_MODELO, stdin);
            v.modelo[strcspn(v.modelo, "\n")] = 0;
            v.status = DISPONIVEL;
            printf("Local atual (índice): ");
            scanf("%d", &v.localAtual);
            getchar();
            if (adicionarVeiculo(veiculos, v))
                printf("Veículo adicionado com sucesso!\n");
            else
                printf("Erro: Placa já cadastrada.\n");
        } else if (opcao == 2) {
            listarVeiculos(veiculos);
        } else if (opcao == 3) {
            char placa[MAX_PLACA];
            printf("Placa do veículo a atualizar: ");
            fgets(placa, MAX_PLACA, stdin);
            placa[strcspn(placa, "\n")] = 0;
            int idx = buscarVeiculoPorPlaca(veiculos, placa);
            if (idx == -1) {
                printf("Veículo não encontrado.\n");
            } else {
                Veiculo v = veiculos->veiculos[idx];
                printf("Novo modelo: ");
                fgets(v.modelo, MAX_MODELO, stdin);
                v.modelo[strcspn(v.modelo, "\n")] = 0;
                printf("Novo status (0=Disponível, 1=Ocupado): ");
                int st;
                scanf("%d", &st);
                getchar();
                v.status = st == 0 ? DISPONIVEL : OCUPADO;
                printf("Novo local atual (índice): ");
                scanf("%d", &v.localAtual);
                getchar();
                if (atualizarVeiculo(veiculos, placa, v))
                    printf("Veículo atualizado!\n");
                else
                    printf("Erro ao atualizar.\n");
            }
        } else if (opcao == 4) {
            char placa[MAX_PLACA];
            printf("Placa do veículo a remover: ");
            fgets(placa, MAX_PLACA, stdin);
            placa[strcspn(placa, "\n")] = 0;
            if (removerVeiculo(veiculos, placa))
                printf("Veículo removido!\n");
            else
                printf("Veículo não encontrado.\n");
        }
    } while(opcao != 0);
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
                submenuVeiculos(&veiculos);
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
