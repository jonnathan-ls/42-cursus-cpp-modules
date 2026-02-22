# CPP Module 06 - Exercício 00: Conversão de Tipos Escalares

Este exercício introduz a conversão explícita entre tipos escalares em C++, utilizando `static_cast` para demonstrar como o programa deve transformar literais entre `char`, `int`, `float` e `double`.

## 🎯 Objetivos Pedagógicos
O foco é compreender como o C++ trata a conversão entre tipos primitivos, detectar literais a partir de strings, e aplicar `static_cast` de forma explícita com tratamento de erros via **exceptions**.

## 🧬 Conceitos Fundamentais

### 1. Detecção de Tipo (Parsing)
O programa recebe uma string e precisa identificar qual tipo escalar ela representa.
- **strtod/strtol**: Funções do C utilizadas para validar e extrair valores numéricos da string em C++98.
- **endptr**: Ponteiro retornado pelas funções `strto*` que indica até onde a string foi consumida, permitindo verificar se é um literal válido.
- **errno/ERANGE**: Mecanismo do C para detectar overflows durante a conversão de strings para números.

### 2. static_cast e Conversão Explícita
Diferente do cast implícito (que o compilador faz sozinho), o `static_cast` torna a intenção do programador visível.
- **Aquisição no tipo nativo**: O literal é primeiro convertido para seu tipo original (ex: `strtol` para int).
- **Cast explícito**: A partir do tipo adquirido, `static_cast` converte para os 3 outros tipos escalares.
- **Validação antes do cast**: Como `static_cast` entre primitivos nunca lança exceção, os limites devem ser verificados manualmente antes.

### 3. Templates (Função Genérica)
O uso de `template <typename T>` permite criar uma única função de conversão que funciona com qualquer tipo escalar.
- **Instanciação pelo compilador**: Ao chamar `castAllAndPrint(meu_int)`, o compilador gera automaticamente uma versão onde `T = int`.
- **Reuso sem duplicação**: Um único template substitui 4 funções quase idênticas.

### 4. Exceptions como Controle de Fluxo
Cada conversão é protegida por `try/catch`: o validador faz `throw` se o cast é impossível, e o `catch` exibe a mensagem de erro.
- **throw std::runtime_error**: Lançado pelos validadores quando o valor ultrapassa os limites do tipo alvo.
- **Responsabilidade Única**: Validadores só validam, printers só imprimem, o orquestrador (`convert`) coordena.

### 5. Pseudo-literais (IEEE 754)
O padrão IEEE 754 define valores especiais que não são números convencionais.
- **NaN** (Not a Number): Resultado de operações indefinidas como `0.0/0.0`. Propriedade única: `NaN != NaN`.
- **Infinito** (±inf): Resultado de overflow ou divisão por zero. `inf * 2 == inf`.
- **Representação**: float usa `nanf`/`±inff`, double usa `nan`/`±inf`.

> **Nota**: Em C++98, `val != val` é o idioma padrão para detectar NaN, já que `std::isnan` só foi introduzido no C++11.
