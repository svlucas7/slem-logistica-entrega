#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locais.h"
#include "veiculos.h"
#include "pedidos.h"
#include "rota.h"
#include "backup.h"

// Funcao auxiliar para limpar completamente o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Exibe o menu principal do sistema SLEM, mostrando todas as opcoes disponiveis ao usuario
void exibirMenu() {
    printf("\n==== Sistema de Logistica de Entrega de Mercadorias (SLEM) ====\n");
    printf("1. Cadastro de Locais\n");
    printf("2. Cadastro de Veiculos\n");
    printf("3. Cadastro de Pedidos\n");
    printf("4. Calcular e Exibir Rota de Entrega\n");
    printf("5. Backup de dados\n");
    printf("6. Restaurar dados\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

// Submenu para operacoes de veiculos (CRUD)
// Permite adicionar, listar, atualizar e remover veiculos
void submenuVeiculos(ListaVeiculos* veiculos, ListaLocais* locais) {
    int opcao;
    do {
        printf("\n--- Cadastro de Veiculos ---\n");
        printf("1. Adicionar Veiculo\n");
        printf("2. Listar Veiculos\n");
        printf("3. Atualizar Veiculo\n");
        printf("4. Remover Veiculo\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();
        if (opcao == 1) {
            // Adiciona um novo veiculo
            Veiculo v;
            limparBuffer();
            printf("\nPlaca: ");
            fgets(v.placa, MAX_PLACA, stdin);
            v.placa[strcspn(v.placa, "\n")] = 0;
            printf("Modelo: ");
            fgets(v.modelo, MAX_MODELO, stdin);
            v.modelo[strcspn(v.modelo, "\n")] = 0;
            v.status = DISPONIVEL;
            printf("Locais cadastrados:\n");
            listarLocais(locais);
            char nomeLocal[MAX_NOME_LOCAL];
            int idxLocal;
            do {
                printf("Local atual (nome): ");
                fgets(nomeLocal, MAX_NOME_LOCAL, stdin);
                nomeLocal[strcspn(nomeLocal, "\n")] = 0;
                if (strlen(nomeLocal) == 0) {
                    printf("Nome do local nao pode ser vazio. Tente novamente.\n");
                    continue;
                }
                idxLocal = buscarLocalPorNome(locais, nomeLocal);
                if (idxLocal == -1) {
                    printf("Erro: Local nao encontrado. Tente novamente.\n");
                    continue;
                }
                v.localAtual = idxLocal;
                break;
            } while (1);
            if (adicionarVeiculo(veiculos, v))
                printf("Veiculo adicionado com sucesso!\n");
            else
                printf("Erro: Placa ja cadastrada.\n");
        } else if (opcao == 2) {
            listarVeiculos(veiculos);
        } else if (opcao == 3) {
            char placa[MAX_PLACA];
            printf("\nPlaca do veiculo a atualizar: ");
            fgets(placa, MAX_PLACA, stdin);
            placa[strcspn(placa, "\n")] = 0;
            int idx = buscarVeiculoPorPlaca(veiculos, placa);
            if (idx == -1) {
                printf("Veiculo nao encontrado.\n");
            } else {
                Veiculo v = veiculos->veiculos[idx];
                printf("Novo modelo: ");
                fgets(v.modelo, MAX_MODELO, stdin);
                v.modelo[strcspn(v.modelo, "\n")] = 0;
                printf("Novo status (0=Disponivel, 1=Ocupado): ");
                int st;
                scanf("%d", &st);
                limparBuffer();
                v.status = st == 0 ? DISPONIVEL : OCUPADO;
                printf("Locais cadastrados:\n");
                listarLocais(locais);
                char nomeLocal[MAX_NOME_LOCAL];
                int idxLocal;
                do {
                    printf("Novo local atual (nome): ");
                    fgets(nomeLocal, MAX_NOME_LOCAL, stdin);
                    nomeLocal[strcspn(nomeLocal, "\n")] = 0;
                    if (strlen(nomeLocal) == 0) {
                        printf("Nome do local nao pode ser vazio. Tente novamente.\n");
                        continue;
                    }
                    idxLocal = buscarLocalPorNome(locais, nomeLocal);
                    if (idxLocal == -1) {
                        printf("Erro: Local nao encontrado. Tente novamente.\n");
                        continue;
                    }
                    v.localAtual = idxLocal;
                    break;
                } while (1);
                if (atualizarVeiculo(veiculos, placa, v))
                    printf("Veiculo atualizado!\n");
                else
                    printf("Erro ao atualizar.\n");
            }
        } else if (opcao == 4) {
            char placa[MAX_PLACA];
            printf("\nPlaca do veiculo a remover: ");
            fgets(placa, MAX_PLACA, stdin);
            placa[strcspn(placa, "\n")] = 0;
            if (removerVeiculo(veiculos, placa))
                printf("Veiculo removido!\n");
            else
                printf("Veiculo nao encontrado.\n");
        }
    } while(opcao != 0);
}

// funcao principal do sistema
// Inicializa as listas, exibe o menu principal e executa as operacoes escolhidas pelo usuario
int main() {
    ListaLocais locais;
    ListaVeiculos veiculos;
    ListaPedidos pedidos;
    inicializarListaLocais(&locais); // Vetor dinamico de locais
    inicializarListaVeiculos(&veiculos); // Vetor dinamico de veiculos
    inicializarListaPedidos(&pedidos); // Vetor dinamico de pedidos

    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: {
                // Submenu para CRUD de Locais
                int opLocal;
                do {
                    printf("\n--- Cadastro de Locais ---\n");
                    printf("1. Adicionar Local\n");
                    printf("2. Listar Locais\n");
                    printf("3. Atualizar Local\n");
                    printf("4. Remover Local\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opLocal);
                    getchar(); // Limpar buffer
                    if (opLocal == 1) {
                        // Adiciona um novo local
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
                            printf("Local ja existe!\n");
                    } else if (opLocal == 2) {
                        // Lista todos os locais
                        listarLocais(&locais);
                    } else if (opLocal == 3) {
                        // Atualiza um local existente
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
                        // Remove um local pelo nome
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
                // Submenu para CRUD de veiculos
                submenuVeiculos(&veiculos, &locais);
                break;
            case 3: {
                // Submenu para CRUD de Pedidos
                int opPedido;
                do {
                    printf("\n--- Cadastro de Pedidos ---\n");
                    printf("1. Adicionar Pedido\n");
                    printf("2. Listar Pedidos\n");
                    printf("3. Atualizar Pedido\n");
                    printf("4. Remover Pedido\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opPedido);
                    limparBuffer();
                    if (opPedido == 1) {
                        Pedido p;
                        printf("ID do pedido: ");
                        scanf("%d", &p.id);
                        limparBuffer();
                        printf("Locais cadastrados:\n");
                        listarLocais(&locais);
                        char nomeOrigem[MAX_NOME_LOCAL];
                        int idxOrigem;
                        do {
                            printf("Nome do local de origem: ");
                            fgets(nomeOrigem, MAX_NOME_LOCAL, stdin);
                            nomeOrigem[strcspn(nomeOrigem, "\n")] = 0;
                            if (strlen(nomeOrigem) == 0) {
                                printf("Nome do local nao pode ser vazio. Tente novamente.\n");
                                continue;
                            }
                            idxOrigem = buscarLocalPorNome(&locais, nomeOrigem);
                            if (idxOrigem == -1) {
                                printf("Erro: Local de origem nao encontrado. Tente novamente.\n");
                                continue;
                            }
                            p.origem = idxOrigem;
                            break;
                        } while (1);
                        char nomeDestino[MAX_NOME_LOCAL];
                        int idxDestino;
                        do {
                            printf("Nome do local de destino: ");
                            fgets(nomeDestino, MAX_NOME_LOCAL, stdin);
                            nomeDestino[strcspn(nomeDestino, "\n")] = 0;
                            if (strlen(nomeDestino) == 0) {
                                printf("Nome do local nao pode ser vazio. Tente novamente.\n");
                                continue;
                            }
                            idxDestino = buscarLocalPorNome(&locais, nomeDestino);
                            if (idxDestino == -1) {
                                printf("Erro: Local de destino nao encontrado. Tente novamente.\n");
                                continue;
                            }
                            p.destino = idxDestino;
                            break;
                        } while (1);
                        printf("Peso (kg): ");
                        scanf("%f", &p.peso);
                        limparBuffer();
                        if (adicionarPedido(&pedidos, p))
                            printf("Pedido adicionado!\n");
                        else
                            printf("Pedido ja existe!\n");
                    } else if (opPedido == 2) {
                        listarPedidos(&pedidos);
                    } else if (opPedido == 3) {
                        int id;
                        printf("ID do pedido a atualizar: ");
                        scanf("%d", &id);
                        limparBuffer();
                        int idx = buscarPedidoPorId(&pedidos, id);
                        if (idx == -1) {
                            printf("Pedido nao encontrado!\n");
                        } else {
                            Pedido novo;
                            printf("Novo ID: ");
                            scanf("%d", &novo.id);
                            limparBuffer();
                            printf("Locais cadastrados:\n");
                            listarLocais(&locais);
                            char nomeOrigem[MAX_NOME_LOCAL];
                            int idxOrigem;
                            do {
                                printf("Novo nome do local de origem: ");
                                fgets(nomeOrigem, MAX_NOME_LOCAL, stdin);
                                nomeOrigem[strcspn(nomeOrigem, "\n")] = 0;
                                if (strlen(nomeOrigem) == 0) {
                                    printf("Nome do local nao pode ser vazio. Tente novamente.\n");
                                    continue;
                                }
                                idxOrigem = buscarLocalPorNome(&locais, nomeOrigem);
                                if (idxOrigem == -1) {
                                    printf("Erro: Local de origem nao encontrado. Tente novamente.\n");
                                    continue;
                                }
                                novo.origem = idxOrigem;
                                break;
                            } while (1);
                            char nomeDestino[MAX_NOME_LOCAL];
                            int idxDestino;
                            do {
                                printf("Novo nome do local de destino: ");
                                fgets(nomeDestino, MAX_NOME_LOCAL, stdin);
                                nomeDestino[strcspn(nomeDestino, "\n")] = 0;
                                if (strlen(nomeDestino) == 0) {
                                    printf("Nome do local nao pode ser vazio. Tente novamente.\n");
                                    continue;
                                }
                                idxDestino = buscarLocalPorNome(&locais, nomeDestino);
                                if (idxDestino == -1) {
                                    printf("Erro: Local de destino nao encontrado. Tente novamente.\n");
                                    continue;
                                }
                                novo.destino = idxDestino;
                                break;
                            } while (1);
                            printf("Novo peso (kg): ");
                            scanf("%f", &novo.peso);
                            limparBuffer();
                            if (atualizarPedido(&pedidos, id, novo))
                                printf("Pedido atualizado!\n");
                            else
                                printf("Erro ao atualizar!\n");
                        }
                    } else if (opPedido == 4) {
                        int id;
                        printf("ID do pedido a remover: ");
                        scanf("%d", &id);
                        limparBuffer();
                        if (removerPedido(&pedidos, id))
                            printf("Pedido removido!\n");
                        else
                            printf("Pedido nao encontrado!\n");
                    }
                } while(opPedido != 0);
                break;
            }
            case 4:
                // Calcula e exibe a rota de entrega para um pedido selecionado
                if (pedidos.quantidade == 0) {
                    printf("Nenhum pedido cadastrado!\n");
                    break;
                }
                listarPedidos(&pedidos);
                printf("Digite o ID do pedido para calcular a rota: ");
                int idPedido;
                scanf("%d", &idPedido);
                limparBuffer();
                int idxPedido = buscarPedidoPorId(&pedidos, idPedido);
                if (idxPedido == -1) {
                    printf("Pedido nao encontrado!\n");
                    break;
                }
                exibirRotaEntrega(&veiculos, &locais, &pedidos, idPedido);
                break;
            case 5:
                // Realiza backup dos dados em arquivos binarios
                if (salvarBackup(&locais, &veiculos, &pedidos))
                    printf("Backup realizado com sucesso!\n");
                else
                    printf("Erro ao realizar backup!\n");
                break;
            case 6:
                // Restaura os dados dos arquivos binarios
                if (restaurarBackup(&locais, &veiculos, &pedidos))
                    printf("Dados restaurados com sucesso!\n");
                else
                    printf("Erro ao restaurar dados!\n");
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("opcao invalida!\n");
        }
    } while(opcao != 0);

    // Libera toda a memoria alocada antes de encerrar o programa
    destruirListaLocais(&locais);
    destruirListaVeiculos(&veiculos);
    destruirListaPedidos(&pedidos);
    return 0;
}
