# CPP Module 07 - Exercício 00: Template Functions I

Este exercício introduz **template functions**, demonstrando como escrever funções que funcionam com qualquer tipo de dado usando genéricos em tempo de compilação.

## 🎯 Objetivos Pedagógicos

Compreender os fundamentos de templates em C++:
- Escrever funções que aceitam **tipos genéricos** como parâmetro
- Demonstrar **instanciação automática** do compilador para cada tipo usado
- Compreender **constraints implícitas** — requisitos que o tipo T precisa satisfazer
- Reconhecer que **templates não são realmente funções** até compilação

## 🧬 Conceitos Fundamentais

### 1. Template Functions - Moldes, Não Funções

Uma template function não é uma função real. É um **molde (template)** que o compilador usa para gerar funções específicas em tempo de compilação. Quando você chama `max(5, 3)`, o compilador instancia uma versão para `int`. Quando chama `max(3.14, 2.71)`, gera outra para `double`. Cada tipo diferente resulta em bytecode separado no arquivo final.

### 2. Instanciação Automática

O compilador examina os argumentos passados e deduz automaticamente qual tipo T deve ser. Este processo acontece **em tempo de compilação**, não runtime. Se o tipo deduzido não couber em um único contexto (por exemplo, passar `int` e `float` para a mesma chamada), o compilador reporta ambiguidade. Quando há dúvida, você pode especificar explicitamente o tipo.

### 3. Constraints Implícitas - Operadores Necessários

Uma template function não declara explicitamente quais operadores o tipo T precisa ter. Os requisitos estão **implícitos no corpo da função**. Se a função usa `a < b`, então T **obrigatoriamente** precisa ter `operator<` definido. Se não tiver, erro de compilação. Nada é verificado antecipadamente — só quando você tenta usar a template com um tipo que não satisfaz os requisitos.

### 4. Type Deduction

O compilador tenta inferir T automaticamente a partir dos argumentos. Se houver ambiguidade ou incompatibilidade, deduction falha e compilação falha. Para resolver, você pode especificar explicitamente o tipo template, forçando a instanciação com aquele tipo específico, mesmo que haja conversões implícitas.

### 5. Namespace Resolution - O Operador `::`

Se o header `<algorithm>` (ou similar) foi incluído, a STL define suas próprias versões de `swap`, `min`, `max` no namespace `std`. Quando você chama `swap(a, b)` sem qualificação, o compilador fica em dúvida: é a versão global ou a do STL? O operador `::` força busca no escopo global, evitando ambiguidade. Por isso os testes usam `::swap`, `::min`, `::max`.

### 6. Templates vs Herança Virtual

Templates e virtual inheritance resolvem problemas diferentes. **Virtual functions**: Uma implementação real, múltiplos comportamentos decididos em runtime via ponteiro virtual. **Templates**: Múltiplas implementações geradas em compile-time, cada uma otimizada para seu tipo. Templates não têm overhead de indireção (mais rápidas), mas deixam o binary maior.

> **Nota**: Templates só compila os tipos realmente usados no código. Se você nunca chama `max(string, string)`, aquela instanciação nunca é gerada.
