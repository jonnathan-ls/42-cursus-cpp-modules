#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}

AForm *Intern::createShrubberyForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialForm(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target) {
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm *(Intern::*forms[])(std::string) = {
        &Intern::createShrubberyForm,
        &Intern::createRobotomyForm,
        &Intern::createPresidentialForm
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << GREEN << "📄 Intern create: " << RESET << formName << " form!" << std::endl;
            return (this->*forms[i])(target);
        }
    }
    throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
    return "Intern: Form not found!";
}