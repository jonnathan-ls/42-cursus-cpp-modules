# CPP Module 05 - Exercício 01: Formulários e Assinaturas

Neste exercício, a complexidade aumenta ao introduzir a interação entre diferentes objetos e a utilização de atributos constantes dentro de uma classe.

## 🎯 Objetivos Pedagógicos
O objetivo é aprender como um objeto (`Bureaucrat`) pode alterar o estado de outro objeto (`Form`) respeitando regras de acesso e níveis de autoridade, além de lidar com a imutabilidade de atributos.

## 🧬 Conceitos Fundamentais

### 1. Atributos Constantes (const)
A classe `Form` introduz atributos que não podem ser alterados após a criação do objeto, como o nome e os níveis necessários para assinar e executar.
- **Desafio**: Como esses atributos são `const`, eles devem ser obrigatoriamente inicializados na **Lista de Inicialização** do construtor, antes mesmo do corpo do construtor começar a rodar.

### 2. Interação entre Classes
O coração deste exercício é a colaboração entre `Bureaucrat` e `Form`.
- **Método beSigned()**: O formulário decide se permite ser assinado com base no nível do burocrata que o recebeu como parâmetro.
- **Método signForm()**: O burocrata tenta assinar o formulário e fornece feedback visual (sucesso ou motivo do erro), capturando a exceção internamente para manter o fluxo do programa.

### 3. Responsabilidade Delegada
Aprendemos que a lógica de "posso ou não assinar" pertence ao formulário, mas a ação de "tentar assinar" é disparada pelo burocrata. Essa separação de responsabilidades é essencial para um bom design de software.

### 4. Expansão do Sistema de Exceções
Assim como no exercício anterior, o `Form` possui suas próprias exceções. Isso demonstra que cada classe deve ser responsável pelos seus próprios erros de domínio (regras de negócio).

---
> **Nota de Estudo**: Observar a importância da passagem por referência (`const Bureaucrat &`) nos parâmetros. Isso evita cópias desnecessárias de objetos e permite que a classe acesse os dados do burocrata de forma eficiente.
