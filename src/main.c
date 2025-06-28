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
            case 1: {
                int opLocal;
                do {
                    printf("\n--- Cadastro de Locais ---\n");
                    printf("1. Adicionar Local\n");
                    printf("2. Listar Locais\n");
                    printf("3. Atualizar Local\n");
                    printf("4. Remover Local\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opLocal);
                    getchar(); // Limpar buffer
                    if (opLocal == 1) {
                        Local l;
                        printf("Nome do local: ");
                        fgets(l.nome, MAX_NOME_LOCAL, stdin);
                        l.nome[strcspn(l.nome, "\n")] = 0;
                        printf("Coordenada X: ");
                        scanf("%f", &l.x);
                        printf("Coordenada Y: ");
                        scanf("%f", &l.y);
                        if (adicionarLocal(&locais, l))
                            printf("Local adicionado!\n");
                        else
                            printf("Local já existe!\n");
                    } else if (opLocal == 2) {
                        listarLocais(&locais);
                    } else if (opLocal == 3) {
                        char nome[MAX_NOME_LOCAL];
                        printf("Nome do local a atualizar: ");
                        fgets(nome, MAX_NOME_LOCAL, stdin);
                        nome[strcspn(nome, "\n")] = 0;
                        int idx = buscarLocalPorNome(&locais, nome);
                        if (idx == -1) {
                            printf("Local não encontrado!\n");
                        } else {
                            Local novo;
                            printf("Novo nome: ");
                            fgets(novo.nome, MAX_NOME_LOCAL, stdin);
                            novo.nome[strcspn(novo.nome, "\n")] = 0;
                            printf("Nova coordenada X: ");
                            scanf("%f", &novo.x);
                            printf("Nova coordenada Y: ");
                            scanf("%f", &novo.y);
                            if (atualizarLocal(&locais, nome, novo))
                                printf("Local atualizado!\n");
                            else
                                printf("Erro ao atualizar!\n");
                        }
                    } else if (opLocal == 4) {
                        char nome[MAX_NOME_LOCAL];
                        printf("Nome do local a remover: ");
                        fgets(nome, MAX_NOME_LOCAL, stdin);
                        nome[strcspn(nome, "\n")] = 0;
                        if (removerLocal(&locais, nome))
                            printf("Local removido!\n");
                        else
                            printf("Local não encontrado!\n");
                    }
                } while(opLocal != 0);
                break;
            }
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
