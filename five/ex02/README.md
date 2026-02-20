# CPP Module 05 - Exercício 02: Burocracia e Formulários Concretos

Este exercício explora a transição de formulários básicos para uma estrutura robusta fundamentada nos pilares da Programação Orientada a Objetos (POO). Abaixo estão detalhados os conceitos-chave implementados e o que este projeto visa ensinar.

## 🎯 Objetivos Pedagógicos
O exercício foca no domínio de estruturas avançadas de classe, garantindo que o sistema seja extensível, seguro e utilize o máximo do poder do C++.

## � Conceitos Fundamentais

### 1. Classes Abstratas (Interface e Contrato)
A classe original `Form` foi transformada em `AForm` (Classe Abstrata). 
- **O que define**: A presença de um método virtual puro (`virtual void execute(...) const = 0;`).
- **Propósito**: Impedir a instanciação direta de formulários genéricos. O `AForm` serve apenas como um "blueprint" ou contrato que define atributos e regras comuns, obrigando as classes filhas a implementarem seu próprio comportamento de execução.

### 2. Herança e Especialização
O sistema utiliza herança para criar especializações do formulário base: `ShrubberyCreationForm`, `RobotomyRequestForm` e `PresidentialPardonForm`.
- **Vantagem**: Reaproveitamento de código. Os atributos de assinatura e níveis de acesso residem na classe pai, enquanto a lógica única de cada formulário (criar arquivos, simular robotomia ou conceder perdão) fica isolada nas classes filhas.

### 3. Polimorfismo Dinâmico
O polimorfismo permite que o `Bureaucrat` interaja com qualquer formulário através da interface da classe base.
- **Mecanismo**: Ao utilizar `AForm const &` nos parâmetros de execução, o compilador utiliza a *Vtable* para decidir em tempo de execução qual método `execute()` chamar.
    - **Vtable**: É uma tabela que contém ponteiros para os métodos virtuais de uma classe.
- **Conceito**: O "Burocrata" não precisa conhecer os detalhes de cada formulário; ele apenas orquestra a execução, demonstrando desacoplamento de código.

### 4. Gestão de Fluxo via Exceções (Exception Handling)
Em vez de retornos de erro manuais, o projeto utiliza uma hierarquia de classes de exceção herdadas de `std::exception`.
- **Checklist de Segurança**: Antes da execução, o sistema verifica automaticamente se o formulário está assinado e se o nível do executor é suficiente, lançando exceções específicas (`FormNotSignedException` ou `GradeTooLowException`) caso as condições não sejam atendidas.

### 5. Mecânicas de Aleatoriedade e Persistência
- **Randomização**: No `RobotomyRequestForm`, implementa-se a lógica de semente (`srand`) e sorteio (`rand`) para garantir 50% de chance de sucesso.
- **Manipulação de Arquivos**: O `ShrubberyCreationForm` demonstra o uso de streams de saída (`std::ofstream`) para persistência de dados em disco.

---
> **Nota de Estudo**: A correta implementação do **Destrutor Virtual** na classe base é essencial para evitar vazamentos de memória (memory leaks) ao lidar com polimorfismo e destruição de objetos das classes filhas.
