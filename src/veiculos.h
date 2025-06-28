#ifndef VEICULOS_H
#define VEICULOS_H

#define MAX_PLACA 10
#define MAX_MODELO 50

typedef enum { DISPONIVEL, OCUPADO } StatusVeiculo;

typedef struct {
    char placa[MAX_PLACA]; // identificador único
    char modelo[MAX_MODELO];
    StatusVeiculo status;
    int localAtual; // índice do Local
} Veiculo;

typedef struct {
    Veiculo* veiculos;
    int quantidade;
    int capacidade;
} ListaVeiculos;

void inicializarListaVeiculos(ListaVeiculos* lista);
void destruirListaVeiculos(ListaVeiculos* lista);
int adicionarVeiculo(ListaVeiculos* lista, Veiculo veiculo);
int buscarVeiculoPorPlaca(ListaVeiculos* lista, const char* placa);
int atualizarVeiculo(ListaVeiculos* lista, const char* placa, Veiculo novoVeiculo);
int removerVeiculo(ListaVeiculos* lista, const char* placa);
void listarVeiculos(ListaVeiculos* lista);

#endif // VEICULOS_H
