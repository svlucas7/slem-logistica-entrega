#include "../src/pedidos.h"
#include "munit.h"

static MunitResult test_adicionar_e_buscar_pedido(const MunitParameter params[], void* data) {
    ListaPedidos lista;
    inicializarListaPedidos(&lista);
    Pedido p = {1, 0, 1, 10.0f};
    munit_assert(adicionarPedido(&lista, p) == 1);
    munit_assert(buscarPedidoPorId(&lista, 1) == 0);
    destruirListaPedidos(&lista);
    return MUNIT_OK;
}

static MunitResult test_atualizar_pedido(const MunitParameter params[], void* data) {
    ListaPedidos lista;
    inicializarListaPedidos(&lista);
    Pedido p = {2, 0, 1, 5.0f};
    adicionarPedido(&lista, p);
    Pedido novo = {2, 1, 2, 7.5f};
    munit_assert(atualizarPedido(&lista, 2, novo) == 1);
    munit_assert(lista.pedidos[0].peso == 7.5f && lista.pedidos[0].origem == 1);
    destruirListaPedidos(&lista);
    return MUNIT_OK;
}

static MunitResult test_remover_pedido(const MunitParameter params[], void* data) {
    ListaPedidos lista;
    inicializarListaPedidos(&lista);
    Pedido p = {3, 0, 1, 2.0f};
    adicionarPedido(&lista, p);
    munit_assert(removerPedido(&lista, 3) == 1);
    munit_assert(lista.quantidade == 0);
    destruirListaPedidos(&lista);
    return MUNIT_OK;
}

static MunitTest tests[] = {
    {"/adicionar_e_buscar", test_adicionar_e_buscar_pedido, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/atualizar", test_atualizar_pedido, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/remover", test_remover_pedido, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
    "/pedidos", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
