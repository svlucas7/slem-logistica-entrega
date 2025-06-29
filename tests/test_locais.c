#include "../src/locais.h"
#include "munit.h"
#include <string.h>

// Testa a adição de um local e a busca pelo nome
static MunitResult test_adicionar_e_buscar_local(const MunitParameter params[], void* data) {
    ListaLocais lista;
    inicializarListaLocais(&lista);
    Local l = {"TesteLocal", 1.0, 2.0};
    munit_assert(adicionarLocal(&lista, l) == 1); // Deve adicionar com sucesso
    munit_assert(buscarLocalPorNome(&lista, "TesteLocal") == 0); // Deve encontrar na posição 0
    destruirListaLocais(&lista);
    return MUNIT_OK;
}

// Testa a atualização dos dados de um local existente
static MunitResult test_atualizar_local(const MunitParameter params[], void* data) {
    ListaLocais lista;
    inicializarListaLocais(&lista);
    Local l = {"LocalA", 1.0, 2.0};
    adicionarLocal(&lista, l);
    Local novo = {"LocalA", 3.0, 4.0};
    munit_assert(atualizarLocal(&lista, "LocalA", novo) == 1); // Deve atualizar com sucesso
    munit_assert(lista.locais[0].x == 3.0f && lista.locais[0].y == 4.0f); // Verifica atualização
    destruirListaLocais(&lista);
    return MUNIT_OK;
}

// Testa a remoção de um local pelo nome
static MunitResult test_remover_local(const MunitParameter params[], void* data) {
    ListaLocais lista;
    inicializarListaLocais(&lista);
    Local l = {"LocalB", 1.0, 2.0};
    adicionarLocal(&lista, l);
    munit_assert(removerLocal(&lista, "LocalB") == 1); // Deve remover com sucesso
    munit_assert(lista.quantidade == 0); // Lista deve ficar vazia
    destruirListaLocais(&lista);
    return MUNIT_OK;
}

// Array de testes para o módulo de locais
static MunitTest tests[] = {
    {"/adicionar_e_buscar", test_adicionar_e_buscar_local, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/atualizar", test_atualizar_local, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/remover", test_remover_local, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

// Suite de testes do módulo de locais
static const MunitSuite suite = {
    "/locais", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

// Função principal dos testes automatizados
int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
