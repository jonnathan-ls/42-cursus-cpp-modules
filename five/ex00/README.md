# CPP Module 05 - Exercício 00: Primeiro Contato com Burocracia

Este exercício marca a introdução ao tratamento de erros estruturado em C++, utilizando o conceito de Burocratas para demonstrar como o programa deve reagir a estados inválidos.

## 🎯 Objetivos Pedagógicos
O foco aqui é aprender a utilizar o mecanismo de **Exceptions** para garantir que um objeto nunca exista em um estado inválido e que operações proibidas sejam interrompidas de forma limpa.

## 🧬 Conceitos Fundamentais

### 1. Try, Catch e Throw
Diferente do retorno de valores (como 0 ou -1), as exceções permitem "lançar" um erro que interrompe o fluxo normal até ser "capturado".
- **Throw**: Usado para disparar o erro quando detectamos um nível inferior a 1 ou superior a 150.
- **Try/Catch**: Bloco usado no `main` para tentar executar códigos de risco e capturar eventuais falhas sem travar o programa.

### 2. Classes de Exceção Aninhadas
As exceções (`GradeTooHighException` e `GradeTooLowException`) são classes definidas dentro da classe `Bureaucrat`.
- **Herança**: Elas herdam de `std::exception`, o que as torna compatíveis com os blocos `catch` padrão do C++.
- **Método what()**: A sobrescrita do método `what()` permite definir uma mensagem de erro personalizada que será exibida ao capturar a exceção.
    - O uso de `virtual` junto da classe serve para permitir o polimorfismo, e quando utilizada pela classe derivada atua como no uso do ponteiro/referência da classe base, o método chamado será o da classe derivada. [ Sem virtual, a chamada é “fixada” na versão da base (ligação estática). ]

### 3. Encapsulamento e Regras de Negócio
O Burocrata tem um nome e uma classificação (grade). 
- **Restrição**: A classificação deve estar estritamente entre 1 (mais alta) e 150 (mais baixa). 
- **Garantia**: Através do construtor e dos métodos de incremento/decremento, o objeto protege sua própria integridade, não permitindo que um nível inválido seja atribuído.

### 4. Sobrecarga de Operador de Inserção (<<)
Implementação da sobrecarga para facilitar a exibição do estado do Burocrata via `std::cout`, seguindo o formato exigido pelo exercício.

---
> **Nota de Estudo**: Ao incrementar o nível de um burocrata, o valor da classificação *diminui* (ex: de 2 para 1).
