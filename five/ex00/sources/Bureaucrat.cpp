#include "Bureaucrat.hpp"

bool isValidGrade(int grade) {
    return grade >= 1 && grade <= 150;
}

void throwGradeException(int grade) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else {
        throw Bureaucrat::GradeTooLowException();
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "🚨 Grade is too high (highest possible is 1)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "🚨 Grade is too low (lowest possible is 150)";
}

Bureaucrat::Bureaucrat(): name("Default"), grade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name), grade(other.grade) {}

Bureaucrat::Bureaucrat(std::string name, int grade) {
    if (!isValidGrade(grade)) {
        throwGradeException(grade);
    }
    this->name = name;
    this->grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        this->name = other.name;
        this->grade = other.grade;
    }
    return *this;
}

std::string Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::incrementGrade() {
    if (!isValidGrade(this->grade - 1)) {
        throwGradeException(this->grade - 1);
    }
    this->grade--;
}

void Bureaucrat::decrementGrade() {
    if (!isValidGrade(this->grade + 1)) {
        throwGradeException(this->grade + 1);
    }
    this->grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os  << "📄 " << bureaucrat.getName()
        << ", burocrata com classificação " << bureaucrat.getGrade() << ".";
    return os;
}
