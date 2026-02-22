# CPP Module 06 - Exercício 01: Serialization

Este exercício introduz o `reinterpret_cast`, demonstrando como converter ponteiros em representações numéricas inteiras e vice-versa, sem alterar os dados na memória.

## 🎯 Objetivos Pedagógicos
Compreender o `reinterpret_cast` como ferramenta de reinterpretação de bits, diferenciando-o do `static_cast` do ex00 que realiza conversões matemáticas de valor.

## 🧬 Conceitos Fundamentais

### 1. reinterpret_cast
Diferente do `static_cast` (que converte valores), o `reinterpret_cast` reinterpreta os **bits brutos** de um tipo como se fossem outro tipo — sem alterar nenhum bit na memória.
- **Ponteiro → Inteiro**: `reinterpret_cast<uintptr_t>(ptr)` lê o endereço de memória como um número.
- **Inteiro → Ponteiro**: `reinterpret_cast<Data*>(raw)` lê o número de volta como um endereço.
- **Garantia**: A ida e volta (round-trip) preserva o endereço original intacto.

### 2. uintptr_t
Tipo inteiro definido em `<stdint.h>` (C99) com tamanho suficiente para guardar qualquer endereço de memória.
- **32-bit**: `uintptr_t` tem 32 bits (4 bytes).
- **64-bit**: `uintptr_t` tem 64 bits (8 bytes).
- **Em C++98**: Usar `<stdint.h>` (header C) em vez de `<cstdint>` (C++11).

### 3. Serialização vs Exercício
O nome "serialization" no exercício é simplificado. A diferença para a serialização real:
- **Exercício**: Converte o **endereço** (ponteiro) em número. Funciona apenas na mesma execução.
- **Real**: Converte o **conteúdo** (dados) em bytes via `reinterpret_cast<char*>`. Permite envio por rede ou persistência em disco.

### 4. Classe Utilitária (Static)
Assim como no ex00, a classe `Serializer` não deve ser instanciada — apenas expõe métodos estáticos. Construtores e destrutor ficam em `private` (Orthodox Canonical Form).

> **Nota**: O `reinterpret_cast` é o cast mais perigoso do C++ pois o compilador confia cegamente no programador, sem nenhuma verificação de tipo em compile-time ou runtime.
