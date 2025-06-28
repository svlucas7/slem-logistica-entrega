#ifndef LOCAIS_H
#define LOCAIS_H

#define MAX_NOME_LOCAL 100

typedef struct {
    char nome[MAX_NOME_LOCAL]; // identificador único
    float x;
    float y;
} Local;

// Funções CRUD para Locais
typedef struct {
    Local* locais;
    int quantidade;
    int capacidade;
} ListaLocais;

void inicializarListaLocais(ListaLocais* lista);
void destruirListaLocais(ListaLocais* lista);
int adicionarLocal(ListaLocais* lista, Local local);
int buscarLocalPorNome(ListaLocais* lista, const char* nome);
int atualizarLocal(ListaLocais* lista, const char* nome, Local novoLocal);
int removerLocal(ListaLocais* lista, const char* nome);
void listarLocais(ListaLocais* lista);

#endif // LOCAIS_H
