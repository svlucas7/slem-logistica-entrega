# slem-logistica-entrega
Sistema de Logística de Entrega de Mercadorias (Trabalho interdisciplinar - FES + AED1 - PUC Minas)

# Sistema de Logística de Entrega de Mercadorias (SLEM)

## Integrantes
- Lucas Silva
- Gabriel Costa

## Descrição
Sistema para gerenciamento de pedidos, veículos e locais, com cálculo de rotas de entrega, backup/restauração de dados e testes automatizados.

## Estrutura do Projeto
```
src/        # Código-fonte principal
  locais.h/.c
  veiculos.h/.c
  pedidos.h/.c
  rota.h/.c
  backup.h/.c
  main.c
tests/      # Testes automatizados (munit)
data/       # Arquivos binários de backup
```

## Backlog do Produto
| ID  | Funcionalidade                        | Sprint | Responsável     | Status      |
|-----|---------------------------------------|--------|-----------------|-------------|
| 1   | Cadastro de Locais (CRUD)             | 1      | Lucas Silva     | Feito       |
| 2   | Cadastro de Veículos (CRUD)           | 1      | Gabriel Costa   | Feito       |
| 3   | Cadastro de Pedidos (CRUD)            | 2      | Lucas Silva     | Feito       |
| 4   | Cálculo e Exibição de Rota de Entrega | 2      | Gabriel Costa   | Pendente    |
| 5   | Backup e Restauração de Dados         | 3      | Ambos           | Pendente    |
| 6   | Menu Principal e Integração           | 3      | Ambos           | Pendente    |
| 7   | Testes Automatizados (munit)          | 3      | Ambos           | Pendente    |

## Compilação
Utilize um compilador C (gcc) para compilar o projeto. Exemplo:
```sh
gcc src/*.c -o slem
```

## Testes
Os testes automatizados estarão na pasta `tests/` e utilizarão a biblioteca [munit](https://nemequ.github.io/munit/).

## Observações
- Dados são salvos em arquivos binários na pasta `data/`.
- Não utilize o tipo `string`.
- O menu principal está em loop até a opção de sair.

---
Pontifícia Universidade Católica de Minas Gerais
Engenharia de Computação - Fundamentos de Engenharia de Software + AED I
