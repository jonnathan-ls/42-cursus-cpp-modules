#pragma once

#include <string>
#include <exception>
#include "AForm.hpp"

class Intern {
    public:
        Intern();
        ~Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        AForm *makeForm(std::string formName, std::string target);
    
        class FormNotFoundException : public std::exception {
            public:
                const char *what() const throw();
        };

    private:
        AForm *createShrubberyForm(std::string target);
        AForm *createRobotomyForm(std::string target);
        AForm *createPresidentialForm(std::string target);
};

