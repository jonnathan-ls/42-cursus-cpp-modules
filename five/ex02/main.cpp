#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void separator() {
    std::cout << "\n" << CYAN << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET << "\n";
}

int main() {
    // Teste 1: ShrubberyCreationForm
    separator();
    std::cout << BOLD << "TEST 1: ShrubberyCreationForm" << RESET << std::endl;
    
    try {
        Bureaucrat bob("Bob", 137);
        ShrubberyCreationForm shrubbery("home");
        
        std::cout << bob << std::endl;
        std::cout << shrubbery << std::endl;
        
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);
        std::cout << GREEN << "✅ Arquivo home_shrubbery criado!" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    // Teste 2: RobotomyRequestForm
    separator();
    std::cout << BOLD << "TEST 2: RobotomyRequestForm" << RESET << std::endl;
    
    try {
        Bureaucrat alice("Alice", 45);
        RobotomyRequestForm robotomy("Bender");
        
        std::cout << alice << std::endl;
        std::cout << robotomy << std::endl;
        
        alice.signForm(robotomy);
        alice.executeForm(robotomy);
        alice.executeForm(robotomy);
        alice.executeForm(robotomy);
        
    } catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    // Teste 3: PresidentialPardonForm
    separator();
    std::cout << BOLD << "TEST 3: PresidentialPardonForm" << RESET << std::endl;
    
    try {
        Bureaucrat president("President", 5);
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << president << std::endl;
        std::cout << pardon << std::endl;
        
        president.signForm(pardon);
        president.executeForm(pardon);
    } catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    // Teste 4: Tentativa de executar formulário não assinado
    separator();
    std::cout << BOLD << "TEST 4: Formulário Não Assinado" << RESET << std::endl;
    
    try {
        Bureaucrat intern("Intern", 1);
        ShrubberyCreationForm unsigned_form("garden");
        
        std::cout << "Tentando executar formulário não assinado..." << std::endl;
        intern.executeForm(unsigned_form);
    } catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    // Teste 5: Burocrata sem nível suficiente para executar
    separator();
    std::cout << BOLD << "TEST 5: Nível Insuficiente para Executar" << RESET << std::endl;
    
    try {
        Bureaucrat lowLevel("LowLevel", 100);
        RobotomyRequestForm robotomy2("Wall-E");
        Bureaucrat signer("Signer", 1);
        
        signer.signForm(robotomy2);
        std::cout << "Burocrata de nível baixo tentando executar..." << std::endl;
        lowLevel.executeForm(robotomy2);
    } catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    separator();
    std::cout << BOLD << GREEN << "✨ Todos os testes concluídos!" << RESET << "\n" << std::endl;

    return 0;
}
