#include "Form.hpp"
#include "Bureaucrat.hpp"

static bool isValidGrade(int grade) {
    return grade >= 1 && grade <= 150;
}

static void throwGradeException(int grade) {
    if (grade < 1) {
        throw Form::GradeTooHighException();
    } else {
        throw Form::GradeTooLowException();
    }
}

const char *Form::GradeTooHighException::what() const throw() {
    return "🚨 Grade is too high (highest possible is 1)";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "🚨 Grade is too low (lowest possible is 150)";
}

Form::Form(): name("Default"), signedForm(false), gradeToSign(150), gradeToExecute(150) {}

Form::~Form() {}

Form::Form(const Form &other): name(other.name), signedForm(other.signedForm), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) 
    : name(name), signedForm(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (!isValidGrade(gradeToSign)) {
        throwGradeException(gradeToSign);
    }
    if (!isValidGrade(gradeToExecute)) {
        throwGradeException(gradeToExecute);
    }
}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        this->signedForm = other.signedForm;
        // Membros const não podem ser reatribuídos
    }
    return *this;
}

std::string Form::getName() const {
    return this->name;
}

bool Form::getSignedForm() const {
    return this->signedForm;
}

int Form::getGradeToSign() const {
    return this->gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeToSign) {
        throw Form::GradeTooLowException();
    }
    this->signedForm = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os  << "📄 " << form.getName()
        << ", form com classificação " << form.getGradeToSign() << ".";
    return os;
}
