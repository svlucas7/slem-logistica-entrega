#include "../src/locais.h"
#include "munit.h"
#include <string.h>

static MunitResult test_adicionar_e_buscar_local(const MunitParameter params[], void* data) {
    ListaLocais lista;
    inicializarListaLocais(&lista);
    Local l = {"TesteLocal", 1.0, 2.0};
    munit_assert(adicionarLocal(&lista, l) == 1);
    munit_assert(buscarLocalPorNome(&lista, "TesteLocal") == 0);
    destruirListaLocais(&lista);
    return MUNIT_OK;
}

static MunitResult test_atualizar_local(const MunitParameter params[], void* data) {
    ListaLocais lista;
    inicializarListaLocais(&lista);
    Local l = {"LocalA", 1.0, 2.0};
    adicionarLocal(&lista, l);
    Local novo = {"LocalA", 3.0, 4.0};
    munit_assert(atualizarLocal(&lista, "LocalA", novo) == 1);
    munit_assert(lista.locais[0].x == 3.0f && lista.locais[0].y == 4.0f);
    destruirListaLocais(&lista);
    return MUNIT_OK;
}

static MunitResult test_remover_local(const MunitParameter params[], void* data) {
    ListaLocais lista;
    inicializarListaLocais(&lista);
    Local l = {"LocalB", 1.0, 2.0};
    adicionarLocal(&lista, l);
    munit_assert(removerLocal(&lista, "LocalB") == 1);
    munit_assert(lista.quantidade == 0);
    destruirListaLocais(&lista);
    return MUNIT_OK;
}

static MunitTest tests[] = {
    {"/adicionar_e_buscar", test_adicionar_e_buscar_local, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/atualizar", test_atualizar_local, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/remover", test_remover_local, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
    "/locais", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
