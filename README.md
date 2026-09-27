# Projeto 1 — Implementação de A.F.D.
**Linguagens Formais e Autômatos — 2026-2 — Mackenzie**
 
## Objetivo
 
Projetar (no JFLAP 7.1) e implementar (em C, padrão ANSI) um AFD que reconheça, a partir de uma única string:
 
- números inteiros, com ou sem sinal negativo
- números em ponto flutuante, com ou sem sinal negativo
- valores monetários, no formato `$1.234.567,89`
A função `scanner` deve ser implementada com rótulos e `goto` (modelo de código apresentado em aula, 10/09), sem nenhum comando de impressão dentro dela.
 
## Integrantes
 
| Nome | RA |
|---|---|
| Sofia Castelli | 10443550 |
| Ana Gabrielle  | 10721801 |
| Isabella de Castro Jorge | 10409762 |
 
## Divisão do trabalho

## Casos de teste obrigatórios
 
A entrega exige exatamente 9 chamadas à função `scanner`, com a string inicializada de forma fixa no início da `main` (não pode ser convertida para outro formato):
 
| Entrada | Saída esperada |
|---|---|
| `21` | INTEIRO |
| `-21` | INTEIRO COM SINAL |
| `021` | ERRO |
| `2.1` | ERRO |
| `2,1` | P.FLUTUANTE |
| `-0,34` | P.FLUTUANTE COM SINAL |
| `05,567` | ERRO |
| `$5.567,78` | VALOR MONETÁRIO |
| `-2.1` | P.FLUTUANTE COM SINAL |

## Compilação
 
O programa deve ser compilado e executado no **Dev-C++ para Windows**, padrão ANSI C.
 
## Entrega
 
- Prazo: **28/09, até 18h**, via Moodle
- Apenas **um** integrante do grupo publica o trabalho
- Todos os arquivos devem conter a identificação completa dos 3 integrantes

## Status
 
- [x] AFD desenhado no JFLAP 
- [x] `scanner()` em C implementado
- [x] `main()` com os 9 testes obrigatórios
- [ ] Testado no Dev-C++ Windows
- [ ] Identificação dos integrantes no cabeçalho do `.c`
- [ ] Zip final revisado e enviado
