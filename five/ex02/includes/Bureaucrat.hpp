#pragma once

#include <string>
#include <exception>
#include <ostream>

class AForm;

class Bureaucrat {
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat &operator=(const Bureaucrat &other);

        const std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        void signForm(AForm &form);
        void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
