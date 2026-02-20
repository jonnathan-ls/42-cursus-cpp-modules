#include "AForm.hpp"
#include "Bureaucrat.hpp"

static bool isValidGrade(int grade) {
    return grade >= 1 && grade <= 150;
}

static void throwGradeException(int grade) {
    if (grade < 1) {
        throw AForm::GradeTooHighException();
    } else {
        throw AForm::GradeTooLowException();
    }
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "🚨 Grade is too high (highest possible is 1)";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "🚨 Grade is too low (lowest possible is 150)";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "🚨 Form is not signed";
}

AForm::AForm(): name("Default"), signedForm(false), gradeToSign(150), gradeToExecute(150) {}

AForm::~AForm() {}

AForm::AForm(const AForm &other): name(other.name), signedForm(other.signedForm), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) 
    : name(name), signedForm(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (!isValidGrade(gradeToSign)) {
        throwGradeException(gradeToSign);
    }
    if (!isValidGrade(gradeToExecute)) {
        throwGradeException(gradeToExecute);
    }
}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        this->signedForm = other.signedForm;
    }
    return *this;
}

std::string AForm::getName() const {
    return this->name;
}

bool AForm::getSignedForm() const {
    return this->signedForm;
}

int AForm::getGradeToSign() const {
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    this->signedForm = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os  << "📄 " << form.getName()
        << ", form com classificação " << form.getGradeToSign() << ".";
    return os;
}
