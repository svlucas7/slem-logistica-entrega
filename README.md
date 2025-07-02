# Sistema de Logística de Entrega de Mercadorias (SLEM)

## Descrição
O SLEM é um sistema desenvolvido em C para gerenciar entregas de mercadorias, permitindo o cadastro e gerenciamento de locais, veículos e pedidos, além do cálculo de rotas de entrega e funcionalidades de backup/restauração de dados. O projeto inclui testes automatizados e documentação completa.

## Integrantes
- Lucas Silva
- Gabriel Costa

## Estrutura do Projeto
```
src/        Código-fonte principal (.c, .h)
tests/      Testes automatizados (munit)
data/       Arquivos binários de backup
docs/       Documentação e diagramas
slem.exe    Executável principal
```

## Funcionalidades
- Cadastro, consulta, atualização e remoção de Locais
- Cadastro, consulta, atualização e remoção de Veículos
- Cadastro, consulta, atualização e remoção de Pedidos
- Cálculo e exibição de rotas de entrega
- Backup e restauração dos dados do sistema
- Testes automatizados para Locais, Veículos e Pedidos

## Compilação
Utilize um compilador C (ex: gcc) para compilar o projeto:
```sh
gcc src/*.c -o slem.exe
```
O executável será gerado como `slem.exe`.

## Execução
Execute o sistema pelo terminal:
```sh
./slem.exe
```

## Testes Automatizados
Os testes estão na pasta `tests/` e utilizam a biblioteca [munit](https://nemequ.github.io/munit/). Para compilar e rodar os testes:
```sh
gcc tests/test_locais.c munit/munit.c src/locais.c -o tests/test_locais.exe
./tests/test_locais.exe

gcc tests/test_veiculos.c munit/munit.c src/veiculos.c -o tests/test_veiculos.exe
./tests/test_veiculos.exe

gcc tests/test_pedidos.c munit/munit.c src/pedidos.c -o tests/test_pedidos.exe
./tests/test_pedidos.exe
```

## Backup e Restauração
Os dados do sistema são salvos em arquivos binários na pasta `data/`. Utilize as opções do menu principal para realizar backup ou restaurar os dados.

## Documentação
- **Diagrama de Arquitetura:** disponível em `docs/diagrama-arquitetura.html`.
- **Análise de Complexidade:** incluída na documentação do projeto.
- **Comentários:** todo o código-fonte está amplamente comentado para facilitar o entendimento.

## Entrega
1. Compacte todo o projeto em um arquivo `.zip` (ex: `SLEM_NomeAluno.zip`), incluindo:
   - Código-fonte (.c, .h, Makefile, etc.)
   - Executável (`slem.exe`)
   - Documentação (Word/PDF)
   - Diagramas (ou inclua no Word)
   - Pasta de testes
2. Envie o `.zip` pelo Canvas até a data definida.
3. Participe da apresentação/entrevista com o professor, demonstrando o sistema e explicando a documentação.
4. Se solicitado, envie também o link do repositório no GitHub.

---
Pontifícia Universidade Católica de Minas Gerais  
Engenharia de Software - Fundamentos de Engenharia de Software + AED I

## Repositório GitHub
🔗 **Link do projeto:** https://github.com/svlucas7/slem-logistica-entrega

## Status do Projeto
✅ **PROJETO FINALIZADO E PRONTO PARA ENTREGA**
- Código funcional completo
- Documentação Scrum com evidências
- Testes automatizados implementados
- Roteiro para vídeo de apresentação
- Todas as funcionalidades implementadas
