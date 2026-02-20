#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) 
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
    : AForm(other), target(other.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->getSignedForm()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::string filename = this->target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }

    file << "       ###" << std::endl;
    file << "      #o###" << std::endl;
    file << "    #####o###" << std::endl;
    file << "   #o#\\#|#/###" << std::endl;
    file << "    ###\\|/#o#" << std::endl;
    file << "     # }|{  #" << std::endl;
    file << "       }|{" << std::endl;
    file << std::endl;
    file << "      _\\|/_" << std::endl;
    file << "       \\|/" << std::endl;
    file << "        |" << std::endl;

    file.close();
}
