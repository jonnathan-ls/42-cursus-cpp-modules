#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) 
    : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
    : AForm(other), target(other.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!this->getSignedForm()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::cout << "🎖️  " << this->target << " foi perdoado por Zaphod Beeblebrox." << std::endl;
}
