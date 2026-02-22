# CPP Module 06 - Exercício 02: Identify real type

Este exercício introduz o `dynamic_cast`, que permite identificar o tipo real de um objeto polimórfico em runtime.

## 🎯 Objetivos Pedagógicos
Compreender o `dynamic_cast` como mecanismo de verificação de tipo em tempo de execução, e como ele se comporta diferentemente com ponteiros (retorna NULL) e referências (lança exceção).

## 🧬 Conceitos Fundamentais

### 1. dynamic_cast
O único cast do C++ que faz verificação em **runtime**. Ele consulta a vtable do objeto para descobrir seu tipo real.
- **Com ponteiro**: `dynamic_cast<A*>(p)` → retorna o ponteiro castado ou `NULL` se falhar.
- **Com referência**: `dynamic_cast<A&>(p)` → retorna a referência castada ou lança `std::bad_cast` se falhar.
- **Requisito**: A classe base **precisa** ter pelo menos um método virtual (a vtable).

### 2. Destrutor Virtual e vtable
Sem um método virtual, o compilador não gera a vtable e o `dynamic_cast` **não compila**. O subject exige destrutor virtual no Base justamente para habilitar o `dynamic_cast` nas classes filhas.

### 3. Referências vs Ponteiros
O exercício pede duas versões de `identify` para demonstrar os dois comportamentos:
- **Ponteiro**: Checagem com `if (result)` — fluxo sequencial, limpo.
- **Referência**: Checagem com `try/catch` — porque referências não podem ser NULL, o único mecanismo de falha é a exceção.

### 4. Proibição de `<typeinfo>`
O header `<typeinfo>` contém `typeid`, que resolve a identificação de tipo em uma linha. A proibição força o uso de `dynamic_cast` para deduzir o tipo por tentativa e erro — que é o aprendizado real do exercício.

> **Nota**: o uso do `typeinfo` facilitaria por fornecer o opcao de identificar o tipo real de um objeto polimórfico em runtime, tornando desnecessário o uso de `dynamic_cast`.