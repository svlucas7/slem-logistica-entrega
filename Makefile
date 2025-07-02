# Makefile para o projeto SLEM
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra
SRCDIR = src
TESTDIR = tests
SOURCES = $(wildcard $(SRCDIR)/*.c)
TEST_SOURCES = $(wildcard $(TESTDIR)/test_*.c)

# Compilação principal
slem.exe: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o slem.exe

# Compilação dos testes
test_locais.exe: $(TESTDIR)/test_locais.c $(TESTDIR)/munit.c $(SRCDIR)/locais.c
	$(CC) $(CFLAGS) -DMUNIT_NO_BUFFER $^ -o $(TESTDIR)/test_locais.exe

test_veiculos.exe: $(TESTDIR)/test_veiculos.c $(TESTDIR)/munit.c $(SRCDIR)/veiculos.c
	$(CC) $(CFLAGS) -DMUNIT_NO_BUFFER $^ -o $(TESTDIR)/test_veiculos.exe

test_pedidos.exe: $(TESTDIR)/test_pedidos.c $(TESTDIR)/munit.c $(SRCDIR)/pedidos.c
	$(CC) $(CFLAGS) -DMUNIT_NO_BUFFER $^ -o $(TESTDIR)/test_pedidos.exe

# Executar todos os testes
test: test_locais.exe test_veiculos.exe test_pedidos.exe
	@echo "Executando testes de locais..."
	@$(TESTDIR)/test_locais.exe || true
	@echo "Executando testes de veículos..."
	@$(TESTDIR)/test_veiculos.exe || true
	@echo "Executando testes de pedidos..."
	@$(TESTDIR)/test_pedidos.exe || true

# Limpeza
clean:
	del /Q slem.exe $(TESTDIR)\*.exe 2>nul || true

# Compilar tudo
all: slem.exe test_locais.exe test_veiculos.exe test_pedidos.exe

.PHONY: clean test all
