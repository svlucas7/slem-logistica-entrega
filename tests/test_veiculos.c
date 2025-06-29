#include "../src/veiculos.h"
#include "munit.h"
#include <string.h>

static MunitResult test_adicionar_e_buscar_veiculo(const MunitParameter params[], void* data) {
    ListaVeiculos lista;
    inicializarListaVeiculos(&lista);
    Veiculo v = {"ABC1234", "ModeloX", DISPONIVEL, 0};
    munit_assert(adicionarVeiculo(&lista, v) == 1);
    munit_assert(buscarVeiculoPorPlaca(&lista, "ABC1234") == 0);
    destruirListaVeiculos(&lista);
    return MUNIT_OK;
}

static MunitResult test_atualizar_veiculo(const MunitParameter params[], void* data) {
    ListaVeiculos lista;
    inicializarListaVeiculos(&lista);
    Veiculo v = {"DEF5678", "ModeloY", DISPONIVEL, 1};
    adicionarVeiculo(&lista, v);
    Veiculo novo = {"DEF5678", "ModeloZ", OCUPADO, 2};
    munit_assert(atualizarVeiculo(&lista, "DEF5678", novo) == 1);
    munit_assert(lista.veiculos[0].status == OCUPADO && strcmp(lista.veiculos[0].modelo, "ModeloZ") == 0);
    destruirListaVeiculos(&lista);
    return MUNIT_OK;
}

static MunitResult test_remover_veiculo(const MunitParameter params[], void* data) {
    ListaVeiculos lista;
    inicializarListaVeiculos(&lista);
    Veiculo v = {"GHI9012", "ModeloW", DISPONIVEL, 3};
    adicionarVeiculo(&lista, v);
    munit_assert(removerVeiculo(&lista, "GHI9012") == 1);
    munit_assert(lista.quantidade == 0);
    destruirListaVeiculos(&lista);
    return MUNIT_OK;
}

static MunitTest tests[] = {
    {"/adicionar_e_buscar", test_adicionar_e_buscar_veiculo, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/atualizar", test_atualizar_veiculo, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/remover", test_remover_veiculo, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
    "/veiculos", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
