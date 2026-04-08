# CPP Module 07 - Exercício 02: Class Templates

Este exercício introduz **template classes**, demonstrando como criar classes genéricas que encapsulam dados de qualquer tipo com segurança de tipo e semântica correta de propriedade.

## 🎯 Objetivos Pedagógicos

Compreender design de classes template:
- Escrever classes que funcionam com **qualquer tipo de elemento**
- Compreender **sintaxe especial** para definir métodos template fora do corpo da classe
- Implementar **deep copy semantics** corretamente com template classes
- Demonstrar **exceções customizadas** aninhadas em classes template
- Reconhecer o padrão de **geração de código** do compilador

## 🧬 Conceitos Fundamentais

### 1. Class Templates - Moldes de Classes

Uma classe template é um **blueprint** para criar classes especializadas. Quando você escreve `Array<int>`, o compilador gera uma classe específica para `int`. `Array<std::string>` gera outra para strings. Cada tipo resulta em uma classe separada no arquivo objeto. Type safety é garantida em compile-time: não há conversões implícitas entre `Array<int>` e `Array<double>`.

### 2. Métodos Template - Sintaxe Fora da Classe

Métodos de uma classe template devem ser definidos **fora do corpo da classe** com sintaxe especial. Cada método requer seu próprio `template <typename T>` prefix, seguido do nome qualificado da classe e do método. Isto é necessário porque, de fora da classe, o compilador não sabe que `T` existe — você precisa dizer explicitamente "este é um método template de Array especializada sobre T".

### 3. Alocação Dinâmica e Inicialização

Quando aloca um array com `new T[n]`, os elementos não são inicializados (comportamento indefinido). Quando usa `new T[n]()` (com parênteses), o compilador chama o **default constructor** de cada elemento. Para tipos como `int`, transforma lixo em zero. Para tipos como `std::string`, já possuem default constructors que garantem valores seguros. Para structs customizadas, você controla o que default constructor faz.

### 4. Deep Copy vs Shallow Copy - Crítico com Heap

Classes que gerenciam memória heap **obrigatoriamente** precisam de copy constructor e assignment operator customizados. **Shallow copy (default)** faz ambas instâncias apontarem o mesmo heap — quando uma é destruída, libera memória que a outra ainda usa. **Deep copy** aloca novo heap e copia dados, deixando instâncias independentes. Modificar uma cópia não afeta original.

### 5. Self-Assignment Check em Assignment Operator

No assignment operator, verificar `this != &other` é crítico. Se alguém fizer `arr = arr`, sem a verificação, você libera memória (`delete[]`), depois tenta copiar dessa mesma memória — undefined behavior. Com a verificação, essa atribuição é ignorada silenciosamente.

### 6. Const Correctness com Operadores

Sobrecarga de `operator[]` para versões const e non-const. A versão non-const retorna `T&` (permita leitura e escrita). A const retorna `const T&` (apenas leitura). Quando você tem referência const para a array, só a versão const é chamada — você não pode modificar elementos através dela. Compilador garante isto em compile-time.

### 7. Exceções Customizadas Aninhadas

Exceções podem ser definidas como classes aninhadas dentro da classe template. Usuários catched a exceção qualificando com o tipo: `catch (Array<int>::OutOfBoundsException &e)`. A exceção herda de `std::exception` e implementa `what()` para mensagens de erro.

> **Nota**: A sintaxe de métodos template é a parte mais "mágica" e fácil de esquecer. Lembre-se: fora da classe, qualifique com `<T>` e prefixe com `template <typename T>`.
