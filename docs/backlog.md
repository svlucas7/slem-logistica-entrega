# Product Backlog - Sistema SLEM

## Visao do Produto
Sistema de Logística de Entrega de Mercadorias (SLEM) para gerenciar locais, veiculos, pedidos e rotas de entrega.

## Product Owner: Professor de FES + AED I
## Scrum Master: Lucas Silva  
## Development Team: Lucas Silva, Gabriel Costa

---

## Epicos e User Stories

### Epico 1: Gestão de Locais
| ID | User Story | Story Points | Sprint | Responsavel | Status |
|----|------------|--------------|--------|-------------|--------|
| US-01 | Como usuário, quero **cadastrar locais** para definir pontos de entrega | 3 | 1 | Lucas Silva | ✅ Feito |
| US-02 | Como usuário, quero **listar locais** para visualizar pontos cadastrados | 2 | 1 | Lucas Silva | ✅ Feito |
| US-03 | Como usuário, quero **atualizar locais** para corrigir informações | 2 | 1 | Lucas Silva | ✅ Feito |
| US-04 | Como usuário, quero **remover locais** desnecessários | 2 | 1 | Lucas Silva | ✅ Feito |

### Epico 2: Gestão de veiculos  
| ID | User Story | Story Points | Sprint | Responsavel | Status |
|----|------------|--------------|--------|-------------|--------|
| US-05 | Como usuário, quero **cadastrar veiculos** para definir frota disponível | 3 | 1 | Gabriel Costa | ✅ Feito |
| US-06 | Como usuário, quero **listar veiculos** para ver frota cadastrada | 2 | 1 | Gabriel Costa | ✅ Feito |
| US-07 | Como usuário, quero **atualizar veiculos** para manter dados corretos | 2 | 1 | Gabriel Costa | ✅ Feito |
| US-08 | Como usuário, quero **remover veiculos** inativos | 2 | 1 | Gabriel Costa | ✅ Feito |

### Epico 3: Gestão de Pedidos
| ID | User Story | Story Points | Sprint | Responsavel | Status |
|----|------------|--------------|--------|-------------|--------|
| US-09 | Como usuário, quero **cadastrar pedidos** vinculados a locais | 5 | 2 | Lucas Silva | ✅ Feito |
| US-10 | Como usuário, quero **listar pedidos** para acompanhar entregas | 2 | 2 | Lucas Silva | ✅ Feito |
| US-11 | Como usuário, quero **atualizar pedidos** para mudar status | 3 | 2 | Lucas Silva | ✅ Feito |
| US-12 | Como usuário, quero **remover pedidos** cancelados | 2 | 2 | Lucas Silva | ✅ Feito |

### Epico 4: Sistema de Rotas
| ID | User Story | Story Points | Sprint | Responsavel | Status |
|----|------------|--------------|--------|-------------|--------|
| US-13 | Como usuário, quero **calcular rotas** para otimizar entregas | 8 | 2 | Gabriel Costa | ✅ Feito |
| US-14 | Como usuário, quero **visualizar rotas** calculadas | 3 | 2 | Gabriel Costa | ✅ Feito |

### Epico 5: Persistência de Dados
| ID | User Story | Story Points | Sprint | Responsavel | Status |
|----|------------|--------------|--------|-------------|--------|
| US-15 | Como usuário, quero **fazer backup** dos dados do sistema | 5 | 3 | Ambos | ✅ Feito |
| US-16 | Como usuário, quero **restaurar dados** de backup anterior | 3 | 3 | Ambos | ✅ Feito |

### Epico 6: Interface e Integração
| ID | User Story | Story Points | Sprint | Responsavel | Status |
|----|------------|--------------|--------|-------------|--------|
| US-17 | Como usuário, quero **menu principal** intuitivo para navegar | 3 | 3 | Ambos | ✅ Feito |
| US-18 | Como usuário, quero **integração completa** entre módulos | 5 | 3 | Ambos | ✅ Feito |

### Epico 7: Qualidade e Testes
| ID | User Story | Story Points | Sprint | Responsavel | Status |
|----|------------|--------------|--------|-------------|--------|
| US-19 | Como dev, quero **testes automatizados** para garantir qualidade | 8 | 3 | Ambos | ✅ Feito |
| US-20 | Como dev, quero **documentação completa** do sistema | 3 | 3 | Ambos | ✅ Feito |

---

## Resumo das Sprints

### Sprint 1 (15-17/06/2025) - "CRUD Básico"
- **Objetivo:** Implementar CRUD de Locais e veiculos
- **Story Points:** 18 pts
- **Status:** ✅ Concluída
- **Velocity:** 18 pts

### Sprint 2 (18-20/06/2025) - "Pedidos e Rotas" 
- **Objetivo:** Implementar CRUD de Pedidos e Sistema de Rotas
- **Story Points:** 15 pts  
- **Status:** ✅ Concluída
- **Velocity:** 15 pts

### Sprint 3 (21-23/06/2025) - "Integração e Qualidade"
- **Objetivo:** Backup, Menu Principal e Testes
- **Story Points:** 22 pts
- **Status:** ✅ Concluída  
- **Velocity:** 22 pts

---

## Métricas do Projeto
- **Total de Story Points:** 55 pts
- **Velocity Média:** 18.3 pts por sprint
- **Duração Total:** 9 dias úteis (3 sprints)
- **Taxa de Conclusão:** 100% (20/20 user stories)

## Definition of Done (DoD)
- [ ] Código implementado e funcionando
- [ ] Documentação da função criada
- [ ] Testes unitários implementados
- [ ] Code review realizado
- [ ] Integração com sistema principal
- [ ] Demo aprovada pelo Product Owner

