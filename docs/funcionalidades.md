# Documentação das Funcionalidades

## Visão Geral
O SLEM permite o gerenciamento de locais, veículos e pedidos, cálculo de rotas, backup/restauração e testes automatizados.

---

### Locais
- **Funções:**
  - `void cadastrar_local(Local *locais, int *num_locais);`
  - `void listar_locais(const Local *locais, int num_locais);`
  - `void atualizar_local(Local *locais, int num_locais);`
  - `void remover_local(Local *locais, int *num_locais);`
- **Descrição:** Permite cadastrar, listar, atualizar e remover locais de entrega.

### Veículos
- **Funções:**
  - `void cadastrar_veiculo(Veiculo *veiculos, int *num_veiculos);`
  - `void listar_veiculos(const Veiculo *veiculos, int num_veiculos);`
  - `void atualizar_veiculo(Veiculo *veiculos, int num_veiculos);`
  - `void remover_veiculo(Veiculo *veiculos, int *num_veiculos);`
- **Descrição:** Permite cadastrar, listar, atualizar e remover veículos.

### Pedidos
- **Funções:**
  - `void cadastrar_pedido(Pedido *pedidos, int *num_pedidos, const Local *locais, int num_locais);`
  - `void listar_pedidos(const Pedido *pedidos, int num_pedidos);`
  - `void atualizar_pedido(Pedido *pedidos, int num_pedidos, const Local *locais, int num_locais);`
  - `void remover_pedido(Pedido *pedidos, int *num_pedidos);`
- **Descrição:** Permite cadastrar, listar, atualizar e remover pedidos de entrega.

### Rotas
- **Função:**
  - `void calcular_rota(const Pedido *pedidos, int num_pedidos, const Local *locais, int num_locais);`
- **Descrição:** Calcula e exibe a melhor rota de entrega com base nos pedidos cadastrados.

### Backup e Restauração
- **Funções:**
  - `void realizar_backup(const Local *locais, int num_locais, const Veiculo *veiculos, int num_veiculos, const Pedido *pedidos, int num_pedidos);`
  - `void restaurar_backup(Local *locais, int *num_locais, Veiculo *veiculos, int *num_veiculos, Pedido *pedidos, int *num_pedidos);`
- **Descrição:** Permite salvar e restaurar todos os dados do sistema.

---

Todas as funções estão documentadas nos arquivos `.h` e `.c` com comentários explicativos sobre parâmetros, retorno e exemplos de uso.
