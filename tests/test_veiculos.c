#include "../src/veiculos.h"
#include "munit.h"
#include <string.h>

// Testa a adição de um veículo e a busca pela placa
static MunitResult test_adicionar_e_buscar_veiculo(const MunitParameter params[], void* data) {
    ListaVeiculos lista;
    inicializarListaVeiculos(&lista);
    Veiculo v = {"ABC1234", "ModeloX", DISPONIVEL, 0};
    munit_assert(adicionarVeiculo(&lista, v) == 1); // Deve adicionar com sucesso
    munit_assert(buscarVeiculoPorPlaca(&lista, "ABC1234") == 0); // Deve encontrar na posição 0
    destruirListaVeiculos(&lista);
    return MUNIT_OK;
}

// Testa a atualização dos dados de um veículo existente
static MunitResult test_atualizar_veiculo(const MunitParameter params[], void* data) {
    ListaVeiculos lista;
    inicializarListaVeiculos(&lista);
    Veiculo v = {"DEF5678", "ModeloY", DISPONIVEL, 1};
    adicionarVeiculo(&lista, v);
    Veiculo novo = {"DEF5678", "ModeloZ", OCUPADO, 2};
    munit_assert(atualizarVeiculo(&lista, "DEF5678", novo) == 1); // Deve atualizar com sucesso
    munit_assert(lista.veiculos[0].status == OCUPADO && strcmp(lista.veiculos[0].modelo, "ModeloZ") == 0); // Verifica atualização
    destruirListaVeiculos(&lista);
    return MUNIT_OK;
}

// Testa a remoção de um veículo pela placa
static MunitResult test_remover_veiculo(const MunitParameter params[], void* data) {
    ListaVeiculos lista;
    inicializarListaVeiculos(&lista);
    Veiculo v = {"GHI9012", "ModeloW", DISPONIVEL, 3};
    adicionarVeiculo(&lista, v);
    munit_assert(removerVeiculo(&lista, "GHI9012") == 1); // Deve remover com sucesso
    munit_assert(lista.quantidade == 0); // Lista deve ficar vazia
    destruirListaVeiculos(&lista);
    return MUNIT_OK;
}

// Array de testes para o módulo de veículos
static MunitTest tests[] = {
    {"/adicionar_e_buscar", test_adicionar_e_buscar_veiculo, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/atualizar", test_atualizar_veiculo, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/remover", test_remover_veiculo, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

// Suite de testes do módulo de veículos
static const MunitSuite suite = {
    "/veiculos", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

// Função principal dos testes automatizados
int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
