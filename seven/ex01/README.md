# CPP Module 07 - Exercício 01: Template Functions II

Este exercício estende template functions para trabalhar com **múltiplos tipos genéricos simultaneamente**, demonstrando como callbacks (function pointers e functors) podem ser passados como argumentos template.

## 🎯 Objetivos Pedagógicos

Compreender padrões avançados de templates:
- Escrever funções que aceitam **dois ou mais tipos genéricos distintos**
- Demonstrar **callbacks genéricos** — passing function pointers como template arguments
- Introduzir **functors** (objetos callable) como alternativa type-safe a pointers
- Compreender como **type deduction funciona em múltiplas dimensões**

## 🧬 Conceitos Fundamentais

### 1. Múltiplos Parâmetros Template

Uma função template pode declarar **vários tipos genéricos** completamente independentes. O compilador deduz cada tipo separadamente dos argumentos correspondentes. Se um tipo não poder ser deduzido ou houver ambiguidade, deduction falha. Cada combinação diferente de tipos resulta em uma nova instanciação — código ligeiramente diferente para cada tipo.

### 2. Function Pointers Como Template Arguments

Quando você passa um nome de função (como `printInt`) para um template, o compilador automaticamente converte para um ponteiro função e deduz seu tipo assinatura. O tipo é algo como `void(*)(int)` — ponteiro para função que retorna void e recebe int. Type-safety é preservada: se o template espera um callback diferente, compilação falha.

### 3. Functors - Objetos Callable com Estado

Um **functor** é uma classe ou struct que sobrecarga `operator()`, tornando instâncias "chamáveis" como funções. Ao contrário de function pointers, functors podem carregar **estado** (variáveis membro). Você pode criar múltiplas instâncias do mesmo functor com valores iniciais diferentes, e cada uma funciona independentemente. O compilador geralmente inline functors melhor que pointers, eliminando indireção.

### 4. Type Deduction com Callbacks

O compilador deduz separadamente o tipo do array (`T`) e o tipo do callback (`Func`). Callback pode ser um function pointer, um functor, ou qualquer outro tipo callable. Cada tipo de callback diferente resulta em código diferente gerado. Isso não é runtime dispatch — é compile-time instantiation.

### 5. Passar-por-Referência vs Passar-por-Valor

Se o callback aceita um elemento por-valor, recebe cópia. Se aceita por-referência, recebe referência — pode modificar o elemento no array. O compilador automaticamente escolhe a passagem correta conforme o que o callback declara. Se houver incompatibilidade (callback espera `int&` mas você passa `const int`), erro de compilação. Nenhuma conversão manual necessária — type-safe em compile-time.

### 6. Constraints Implícitas com Callbacks

A função template não verifica se `Func` é realmente "callable" até instantiação. Para que a instanciação suceda, `Func` precisa ser invocável com um elemento do tipo `T`. Se não for, mensagem de erro (geralmente longa, SFINAE-related) é reportada.

> **Nota**: Sem templates, você precisaria de `void*` e casts manuais — nenhuma type-safety. Templates garantem que erros de tipo são descobertos em compile-time, não runtime.
