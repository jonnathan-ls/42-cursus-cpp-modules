# CPP Module 05 - Exercício 03: Atendimento Automatizado (Intern)

Este exercício introduz o conceito de "Fábrica de Objetos" (Factory Pattern) simplificada, focando em como criar instâncias de classes dinamicamente sem poluir o código com lógicas condicionais extensas.

## 🎯 Objetivos Pedagógicos
O objetivo central é aprender a evitar "soluções ilegíveis e confusas" (como cadeias gigantes de `if/else if`), utilizando estruturas de dados mais profissionais para o despacho de funções.

## 🧬 Conceitos Fundamentais

### 1. Despacho Dinâmico via Tabela (Dispatch Table)
Em vez de testar cada nome de formulário manualmente, utilizamos uma combinação de:
- **Array de Strings**: Contém os nomes dos formulários conhecidos.
- **Array de Ponteiros para Funções de Membro**: Contém os endereços dos métodos que sabem criar cada formulário específico.

### 2. Ponteiros para Funções de Membro (`Member Function Pointers`)
Diferente de um ponteiro de função comum, um ponteiro para função de membro precisa ser chamado no contexto de uma instância (`this->*funcao`). Isso permite selecionar o comportamento da classe `Intern` dinamicamente em tempo de execução.

### 3. O Padrão "Fábrica" (Factory Method)
A classe `Intern` atua como uma fábrica. Ela recebe um pedido (string) e entrega um produto (`AForm*`). 
- **Desacoplamento**: O usuário (Burocrata ou `main`) não precisa saber quais tipos de formulários existem ou como instanciá-los; basta pedir ao estagiário.

### 4. Gerenciamento de Memória Dinâmica
Como o `makeForm` retorna um ponteiro (`AForm*`), a responsabilidade de liberar essa memória via `delete` passa para quem chamou a função. Isso reforça a atenção necessária ao ciclo de vida de objetos criados no *Heap*.

### 5. Tratamento de Exceção Personalizado
O uso da `FormNotFoundException` garante que, se um formulário desconhecido for solicitado, o erro seja tratado de forma estruturada, mantendo o padrão de robustez estabelecido nos exercícios anteriores.

---
> **Sugestão de Estudo**: Compare esta implementação com o uso de um `std::map` de ponteiros para funções. Embora o exercício peça uma solução simples, entender como mapear chaves para comportamentos é uma habilidade fundamental em C++ moderno.