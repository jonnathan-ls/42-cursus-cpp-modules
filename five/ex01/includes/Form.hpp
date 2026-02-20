#pragma once

#include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string name;
        bool signedForm;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        Form();
        ~Form();
        Form(const Form &other);
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form &operator=(const Form &other);

        std::string getName() const;
        bool getSignedForm() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const Form &form);