#include <stdio.h>
#include <stdlib.h>
#include "locais.h"
#include "veiculos.h"
#include "pedidos.h"
#include "rota.h"
#include "backup.h"

// Exibe o menu principal do sistema SLEM, mostrando todas as opções disponíveis ao usuário
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

// Submenu para operações de veículos (CRUD)
// Permite adicionar, listar, atualizar e remover veículos
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
        getchar(); // Limpa buffer do teclado
        if (opcao == 1) {
            // Adiciona um novo veículo
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
            // Lista todos os veículos cadastrados
            listarVeiculos(veiculos);
        } else if (opcao == 3) {
            // Atualiza os dados de um veículo existente
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
            // Remove um veículo pelo número da placa
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

// Função principal do sistema
// Inicializa as listas, exibe o menu principal e executa as operações escolhidas pelo usuário
int main() {
    ListaLocais locais;
    ListaVeiculos veiculos;
    ListaPedidos pedidos;
    inicializarListaLocais(&locais); // Vetor dinâmico de locais
    inicializarListaVeiculos(&veiculos); // Vetor dinâmico de veículos
    inicializarListaPedidos(&pedidos); // Vetor dinâmico de pedidos

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
                    printf("Escolha uma opção: ");
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
                            printf("Local já existe!\n");
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
                // Submenu para CRUD de Veículos
                submenuVeiculos(&veiculos);
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
                    printf("Escolha uma opção: ");
                    scanf("%d", &opPedido);
                    getchar();
                    if (opPedido == 1) {
                        // Adiciona um novo pedido
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
                        // Lista todos os pedidos
                        listarPedidos(&pedidos);
                    } else if (opPedido == 3) {
                        // Atualiza um pedido existente
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
                        // Remove um pedido pelo id
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
                // Calcula e exibe a rota de entrega para um pedido selecionado
                if (pedidos.quantidade == 0) {
                    printf("Nenhum pedido cadastrado!\n");
                    break;
                }
                listarPedidos(&pedidos);
                printf("Digite o ID do pedido para calcular a rota: ");
                int idPedido;
                scanf("%d", &idPedido);
                getchar();
                exibirRotaEntrega(&veiculos, &locais, &pedidos, idPedido);
                break;
            case 5:
                // Realiza backup dos dados em arquivos binários
                if (salvarBackup(&locais, &veiculos, &pedidos))
                    printf("Backup realizado com sucesso!\n");
                else
                    printf("Erro ao realizar backup!\n");
                break;
            case 6:
                // Restaura os dados dos arquivos binários
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

    // Libera toda a memória alocada antes de encerrar o programa
    destruirListaLocais(&locais);
    destruirListaVeiculos(&veiculos);
    destruirListaPedidos(&pedidos);
    return 0;
}
