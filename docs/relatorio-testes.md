# Relatório de Execução dos Testes

Este relatório apresenta os principais casos de teste automatizados do sistema SLEM, incluindo entradas, saídas esperadas, saídas reais e o resultado de cada teste.

## Como gerar a saída real dos testes
Execute os testes automatizados e salve a saída em um arquivo de texto:

```sh
gcc tests/test_locais.c munit/munit.c src/locais.c -o tests/test_locais.exe
./tests/test_locais.exe > docs/saida_testes_locais.txt

gcc tests/test_veiculos.c munit/munit.c src/veiculos.c -o tests/test_veiculos.exe
./tests/test_veiculos.exe > docs/saida_testes_veiculos.txt

gcc tests/test_pedidos.c munit/munit.c src/pedidos.c -o tests/test_pedidos.exe
./tests/test_pedidos.exe > docs/saida_testes_pedidos.txt
```

## Exemplo de Caso de Teste

| Teste                | Entrada                        | Saída Esperada         | Saída Real             | Status  |
|----------------------|-------------------------------|------------------------|------------------------|---------|
| Cadastro de Local    | Nome: "Centro", ID: 1         | Local cadastrado       | Local cadastrado       | Passou  |
| Remoção de Veículo   | Placa: "ABC1234"              | Veículo removido       | Veículo removido       | Passou  |
| Pedido inválido      | ID Local inexistente           | Erro de cadastro       | Erro de cadastro       | Passou  |

> Veja os arquivos `docs/saida_testes_*.txt` para a execução completa dos testes automatizados.
