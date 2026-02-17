#include "Bureaucrat.hpp"


#include <iostream>
#include <ostream>
#include <string>
#include <exception>

void build_bureaucrat(std::string name, int grade) {
    try {
        Bureaucrat bureaucrat(name, grade);
        std::cout << bureaucrat << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void perform_action(Bureaucrat &bureaucrat, void (Bureaucrat::*action)()) {
    try {
        (bureaucrat.*action)();
        std::cout << bureaucrat << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {
    // Test instance with success
    build_bureaucrat("John", 1);
    build_bureaucrat("Maria", 150);

    // Test instance with exception
    build_bureaucrat("Ana", 0);
    build_bureaucrat("Pedro", 151);

    // Test increment and decrement with success
    Bureaucrat caio("Caio", 75);
    perform_action(caio, &Bureaucrat::decrementGrade);
    perform_action(caio, &Bureaucrat::incrementGrade);

    // Test increment and decrement with exception
    Bureaucrat cleber("Cleber", 1);
    perform_action(cleber, &Bureaucrat::incrementGrade);
    Bureaucrat without_name;
    perform_action(without_name, &Bureaucrat::decrementGrade);
    return 0;
}