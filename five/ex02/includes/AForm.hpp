#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
    private:
        const std::string   _name;
        bool                _signedForm;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        AForm();
        AForm(const std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        virtual ~AForm();

        AForm &operator=(const AForm &other);

        // Getters
        std::string getName() const;
        bool getSignedForm() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        // Métodos
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0; // Método virtual puro

        // Exceções
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);
