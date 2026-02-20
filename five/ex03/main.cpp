#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "Intern.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main() {
    Intern someRandomIntern;
    AForm* rrf;
    try {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;
    } catch (const Intern::FormNotFoundException& e) {
        std::cerr << RED << "🚨 Error: " << RESET << e.what() << std::endl;
    }
    try {
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        delete rrf;
    } catch (const Intern::FormNotFoundException& e) {
        std::cerr << RED << "🚨 Error: " << RESET << e.what() << std::endl;
    }
    try {
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        delete rrf;
    } catch (const Intern::FormNotFoundException& e) {
        std::cerr << RED << "🚨 Error: " << RESET << e.what() << std::endl;
    }
    try {
        rrf = someRandomIntern.makeForm("invalid form", "Bender");
        delete rrf;
    } catch (const Intern::FormNotFoundException& e) {
        std::cerr << RED << "🚨 Error: " << RESET << e.what() << std::endl;
    }
    return 0;
}
