#ifndef VEICULOS_H
#define VEICULOS_H

#define MAX_PLACA 10
#define MAX_MODELO 50

// Enumeração para status do veículo
typedef enum { DISPONIVEL, OCUPADO } StatusVeiculo;

// Estrutura que representa um veículo
typedef struct {
    char placa[MAX_PLACA]; // identificador único
    char modelo[MAX_MODELO];
    StatusVeiculo status;
    int localAtual; // índice do Local
} Veiculo;

// Estrutura que representa uma lista dinâmica de veículos
typedef struct {
    Veiculo* veiculos;
    int quantidade;
    int capacidade;
} ListaVeiculos;

// Inicializa a lista de veículos
void inicializarListaVeiculos(ListaVeiculos* lista);
// Libera a memória da lista de veículos
void destruirListaVeiculos(ListaVeiculos* lista);
// Adiciona um veículo à lista
int adicionarVeiculo(ListaVeiculos* lista, Veiculo veiculo);
// Busca o índice de um veículo pela placa
int buscarVeiculoPorPlaca(ListaVeiculos* lista, const char* placa);
// Atualiza um veículo identificado pela placa
int atualizarVeiculo(ListaVeiculos* lista, const char* placa, Veiculo novoVeiculo);
// Remove um veículo pela placa
int removerVeiculo(ListaVeiculos* lista, const char* placa);
// Lista todos os veículos cadastrados
void listarVeiculos(ListaVeiculos* lista);

#endif // VEICULOS_H
