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
            case 3: {
                int opPedido;
                do {
                    printf("\n--- Cadastro de Pedidos ---\n");
                    printf("1. Adicionar Pedido\n");
                    printf("2. Listar Pedidos\n");
                    printf("3. Atualizar Pedido\n");
                    printf("4. Remover Pedido\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opPedido);
                    getchar();
                    if (opPedido == 1) {
                        Pedido p;
                        printf("ID do pedido: ");
                        scanf("%d", &p.id);
                        printf("Índice do local de origem: ");
                        scanf("%d", &p.origem);
                        printf("Índice do local de destino: ");
                        scanf("%d", &p.destino);
                        printf("Peso (kg): ");
                        scanf("%f", &p.peso);
                        if (adicionarPedido(&pedidos, p))
                            printf("Pedido adicionado!\n");
                        else
                            printf("Pedido já existe!\n");
                    } else if (opPedido == 2) {
                        listarPedidos(&pedidos);
                    } else if (opPedido == 3) {
                        int id;
                        printf("ID do pedido a atualizar: ");
                        scanf("%d", &id);
                        int idx = buscarPedidoPorId(&pedidos, id);
                        if (idx == -1) {
                            printf("Pedido não encontrado!\n");
                        } else {
                            Pedido novo;
                            printf("Novo ID: ");
                            scanf("%d", &novo.id);
                            printf("Novo índice de origem: ");
                            scanf("%d", &novo.origem);
                            printf("Novo índice de destino: ");
                            scanf("%d", &novo.destino);
                            printf("Novo peso (kg): ");
                            scanf("%f", &novo.peso);
                            if (atualizarPedido(&pedidos, id, novo))
                                printf("Pedido atualizado!\n");
                            else
                                printf("Erro ao atualizar!\n");
                        }
                    } else if (opPedido == 4) {
                        int id;
                        printf("ID do pedido a remover: ");
                        scanf("%d", &id);
                        if (removerPedido(&pedidos, id))
                            printf("Pedido removido!\n");
                        else
                            printf("Pedido não encontrado!\n");
                    }
                } while(opPedido != 0);
                break;
            }
            case 4:
                // Calcular e exibir rota
                break;
            case 5:
                if (salvarBackup(&locais, &veiculos, &pedidos))
                    printf("Backup realizado com sucesso!\n");
                else
                    printf("Erro ao realizar backup!\n");
                break;
            case 6:
                if (restaurarBackup(&locais, &veiculos, &pedidos))
                    printf("Dados restaurados com sucesso!\n");
                else
                    printf("Erro ao restaurar dados!\n");
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
