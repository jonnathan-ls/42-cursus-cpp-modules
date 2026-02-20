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

AForm::AForm(): _name("Default"), _signedForm(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::~AForm() {}

AForm::AForm(const AForm &other): _name(other._name), _signedForm(other._signedForm), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) 
    : _name(name), _signedForm(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (!isValidGrade(gradeToSign)) {
        throwGradeException(gradeToSign);
    }
    if (!isValidGrade(gradeToExecute)) {
        throwGradeException(gradeToExecute);
    }
}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        this->_signedForm = other._signedForm;
    }
    return *this;
}

std::string AForm::getName() const {
    return this->_name;
}

bool AForm::getSignedForm() const {
    return this->_signedForm;
}

int AForm::getGradeToSign() const {
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    this->_signedForm = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os  << "📄 " << form.getName()
        << ", form com classificação " << form.getGradeToSign() << ".";
    return os;
}
