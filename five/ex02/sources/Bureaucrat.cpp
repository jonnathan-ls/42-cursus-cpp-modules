#include "Bureaucrat.hpp"
#include "AForm.hpp"

static bool isValidGrade(int grade) {
    return grade >= 1 && grade <= 150;
}

static void throwGradeException(int grade) {
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

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade) {
    if (!isValidGrade(grade)) {
        throwGradeException(grade);
    }
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        this->grade = other.grade;
        // name nao pode ser reatribuido por ser const
    }
    return *this;
}

const std::string Bureaucrat::getName() const {
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

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << this->name << " assinou " << form.getName() << "." << std::endl;
    } catch (std::exception &e) {
        std::cout << this->name << " não conseguiu assinar " << form.getName() << " porque " << e.what() << "." << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {
    try {
        form.execute(*this);
        std::cout << this->name << " executou " << form.getName() << "." << std::endl;
    } catch (std::exception &e) {
        std::cout << this->name << " não conseguiu executar " << form.getName() << " porque " << e.what() << "." << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os  << "📄 " << bureaucrat.getName()
        << ", burocrata com classificação " << bureaucrat.getGrade() << ".";
    return os;
}
