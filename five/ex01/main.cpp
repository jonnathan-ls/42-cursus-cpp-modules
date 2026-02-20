#include "Bureaucrat.hpp"
#include "Form.hpp"
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
    // Teste 1: Validação de níveis
    separator();
    std::cout << BOLD << "TEST 1: Validação de Níveis" << RESET << std::endl;
    
    try {
        Form f1("Invalid High", 0, 75);
    } catch (std::exception &e) {
        std::cout << "❌ Grade 0: " << e.what() << std::endl;
    }
    
    try {
        Form f2("Invalid Low", 151, 75);
    } catch (std::exception &e) {
        std::cout << "❌ Grade 151: " << e.what() << std::endl;
    }

    // Teste 2: Assinatura bem-sucedida
    separator();
    std::cout << BOLD << "TEST 2: Assinatura Bem-Sucedida" << RESET << std::endl;
    
    Bureaucrat boss("Boss", 1);
    Form contract("Contract", 10, 20);
    std::cout << boss << std::endl;
    std::cout << contract << std::endl;
    boss.signForm(contract);
    std::cout << "✅ Status: " << (contract.getSignedForm() ? GREEN "Assinado" : "Pendente") << RESET << "\n";

    // Teste 3: Assinatura negada
    separator();
    std::cout << BOLD << "TEST 3: Assinatura Negada" << RESET << std::endl;
    
    Bureaucrat intern("Intern", 150);
    Form secret("TopSecret", 1, 1);
    std::cout << intern << std::endl;
    std::cout << secret << std::endl;
    intern.signForm(secret);
    std::cout << "Status: " << (secret.getSignedForm() ? "Assinado" : "Não assinado") << "\n";

    // Teste 4: Validação de const
    separator();
    std::cout << BOLD << "TEST 4: Validação de Membros const" << RESET << std::endl;
    
    Bureaucrat signer("Signer", 1);
    Form original("Original", 42, 42);
    Form assign("Assign", 1, 1);
    
    std::cout << "\n" << YELLOW << "Antes:" << RESET << std::endl;
    std::cout << "Original: " << original.getName() << " [" << original.getGradeToSign() 
              << "/" << original.getGradeToExecute() << "] Signed: " 
              << (original.getSignedForm() ? "Yes" : "No") << std::endl;
    std::cout << "Assign:   " << assign.getName() << " [" << assign.getGradeToSign() 
              << "/" << assign.getGradeToExecute() << "] Signed: " 
              << (assign.getSignedForm() ? "Yes" : "No") << std::endl;
    
    signer.signForm(original);
    assign = original;
    
    std::cout << "\n" << YELLOW << "Depois de assign = original:" << RESET << std::endl;
    std::cout << "Assign:   " << assign.getName() << " [" << assign.getGradeToSign() 
              << "/" << assign.getGradeToExecute() << "] Signed: " 
              << (assign.getSignedForm() ? "Yes" : "No") << std::endl;
    
    std::cout << "\n" << YELLOW << "Validação:" << RESET << std::endl;
    std::cout << "  Nome (const):        " << (assign.getName() == "Assign" ? GREEN "✓" : "✗") << RESET << std::endl;
    std::cout << "  GradeToSign (const): " << (assign.getGradeToSign() == 1 ? GREEN "✓" : "✗") << RESET << std::endl;
    std::cout << "  GradeToExec (const): " << (assign.getGradeToExecute() == 1 ? GREEN "✓" : "✗") << RESET << std::endl;
    std::cout << "  SignedForm:          " << (assign.getSignedForm() == true ? GREEN "✓" : "✗") << RESET << std::endl;

    separator();
    std::cout << BOLD << GREEN << "✨ Todos os testes concluídos!" << RESET << "\n" << std::endl;

    return 0;
}