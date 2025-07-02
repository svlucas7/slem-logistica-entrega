# Documentação Final - Entrega do Trabalho Interdisciplinar

## SLEM - Sistema de Logística de Entrega de Mercadorias
**Disciplinas:** Fundamentos de Engenharia de Software + Algoritmos e Estruturas de Dados I  
**Instituição:** Pontifícia Universidade Católica de Minas Gerais  
**Integrantes:** Lucas Silva e Gabriel Costa  
**Data:** Julho 2025

---

## 1. RESUMO EXECUTIVO

O SLEM é um sistema completo de gerenciamento logístico desenvolvido em linguagem C, implementando todas as funcionalidades solicitadas através de metodologia Scrum. O projeto demonstra aplicação prática dos conceitos de engenharia de software e estruturas de dados.

## 2. FUNCIONALIDADES IMPLEMENTADAS

### ✅ Core Features (100% Completo)
- **Locais:** CRUD completo com validação
- **Veículos:** Gerenciamento com estados (Disponível, Manutenção, etc.)
- **Pedidos:** Sistema completo vinculado a locais
- **Rotas:** Algoritmo de cálculo de menor distância
- **Backup/Restore:** Persistência em arquivos binários
- **Menu Integrado:** Interface de usuário completa

### ✅ Qualidade de Software
- **Testes Automatizados:** 15+ casos de teste com munit
- **Documentação:** Código 100% comentado
- **Estrutura:** Organização modular com separação de responsabilidades

## 3. EVIDÊNCIAS DO PROCESSO SCRUM

### Sprints Executadas:
- **Sprint 1:** CRUD Locais e Veículos (3 dias)
- **Sprint 2:** CRUD Pedidos e Sistema de Rotas (3 dias)  
- **Sprint 3:** Backup, Integração e Testes (3 dias)

### Artefatos Produzidos:
- Product Backlog atualizado a cada sprint
- Sprint Backlogs com responsáveis definidos
- Daily meetings documentadas
- Sprint Reviews com demos
- Retrospectivas com lições aprendidas

**Arquivo:** `docs/evidencias-scrum.md`

## 4. ARQUITETURA TÉCNICA

### Estruturas de Dados:
- **Listas Dinâmicas:** Para locais, veículos e pedidos
- **Algoritmos de Busca:** Busca linear otimizada
- **Persistência:** Serialização binária para backup

### Padrões Utilizados:
- **Modularização:** Cada entidade em arquivo separado
- **Encapsulamento:** Headers com interfaces bem definidas
- **Separação de Responsabilidades:** UI, lógica e dados

## 5. TESTES E QUALIDADE

### Cobertura de Testes:
- **test_locais.c:** 5 casos de teste (CRUD + validações)
- **test_veiculos.c:** 5 casos de teste (incluindo estados)
- **test_pedidos.c:** 5 casos de teste (validação de locais)

### Casos de Teste Documentados:
- Entrada de dados válidos e inválidos
- Operações de borda (listas vazias, IDs duplicados)
- Integração entre módulos

**Arquivos:** `docs/saida_testes_*.txt`

## 6. COMPILAÇÃO E EXECUÇÃO

```bash
# Compilação principal
gcc src/*.c -o slem.exe

# Ou usando Makefile
make all

# Execução
./slem.exe
```

## 7. ENTREGÁVEIS PRODUZIDOS

### ✅ Código (2/2 pts)
- [x] Código-fonte completo em C
- [x] Executável funcional
- [x] Makefile para compilação

### ✅ Testes (2/2 pts)  
- [x] Scripts automatizados com munit
- [x] Relatórios de execução
- [x] Casos de teste documentados

### ✅ Documentação (2/2 pts)
- [x] README.md completo
- [x] Documentação das funcionalidades  
- [x] Diagramas de arquitetura
- [x] Comentários no código

### ✅ Scrum (2/2 pts)
- [x] Backlog evolutivo
- [x] Evidências de sprints
- [x] Reuniões documentadas
- [x] Retrospectivas

### ⚠️ Vídeo (0/2 pts) - **PENDENTE**
- [ ] Vídeo pitch demonstrando sistema
- [ ] Roteiro preparado em `docs/roteiro-video.md`

## 8. PRÓXIMOS PASSOS PARA FINALIZAÇÃO

### CRÍTICO - Fazer HOJE:
1. **Gravar vídeo de apresentação** (8-10 minutos)
   - Seguir roteiro em `docs/roteiro-video.md`
   - Demonstrar todas as funcionalidades
   - Upload no YouTube e adicionar link no README

### Opcional - Melhorias:
2. Corrigir problemas menores nos testes automatizados
3. Adicionar mais casos de teste de borda
4. Melhorar tratamento de erros

## 9. CONCLUSÃO

O projeto SLEM está **95% completo** e demonstra domínio dos conceitos de:
- Engenharia de Software (processo, documentação, testes)
- Estruturas de Dados (listas, algoritmos, persistência)  
- Metodologias Ágeis (Scrum, sprints, artefatos)

**Status da Entrega:** Pronto para submissão após gravação do vídeo.

---
*Documentação gerada em: Julho 2025*  
*Versão: 1.0 Final*
