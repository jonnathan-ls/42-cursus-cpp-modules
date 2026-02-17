#pragma once

#include <string>
#include <exception>
#include <ostream>

class Bureaucrat {
    private:
        std::string name;
        int grade;

    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat(std::string name, int grade);
        Bureaucrat &operator=(const Bureaucrat &other);

        std::string getName() const;
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
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
