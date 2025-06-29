#ifndef LOCAIS_H
#define LOCAIS_H

#define MAX_NOME_LOCAL 100

// Estrutura que representa um local (nome, coordenadas)
typedef struct {
    char nome[MAX_NOME_LOCAL]; // identificador único
    float x;
    float y;
} Local;

// Estrutura que representa uma lista dinâmica de locais
typedef struct {
    Local* locais;
    int quantidade;
    int capacidade;
} ListaLocais;

// Inicializa a lista de locais
void inicializarListaLocais(ListaLocais* lista);
// Libera a memória da lista de locais
void destruirListaLocais(ListaLocais* lista);
// Adiciona um local à lista
int adicionarLocal(ListaLocais* lista, Local local);
// Busca o índice de um local pelo nome
int buscarLocalPorNome(ListaLocais* lista, const char* nome);
// Atualiza um local identificado pelo nome
int atualizarLocal(ListaLocais* lista, const char* nome, Local novoLocal);
// Remove um local pelo nome
int removerLocal(ListaLocais* lista, const char* nome);
// Lista todos os locais cadastrados
void listarLocais(ListaLocais* lista);

#endif // LOCAIS_H
