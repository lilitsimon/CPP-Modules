#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other )
: AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if(this != &other) {
        AForm::operator=(other);
        target= other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (!getIsSigned()) {
        std::cerr << "Form is not signed!" << std::endl;
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        std::cerr << "Grade too low to execute!" << std::endl;
        throw GradeTooLowException();
    }

    std::ofstream file((target + "_shrubbery").c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not create or open file." << std::endl;
        return;
    }
    file << "         &        " << std::endl;
    file << "        &&&        " << std::endl;
    file << "       &&&&&       " << std::endl;
    file << "      &&&&&&&      " << std::endl;
    file << "     &&&&&&&&&     " << std::endl;
    file << "    &&&&&&&&&&&    " << std::endl;
    file << "   &&&&&&&&&&&&&   " << std::endl;
    file << "  &&&&&&&&&&&&&&&  " << std::endl;
    file << "        |||        " << std::endl;
    file << "        |||        " << std::endl;

    file.close();
    std::cout << "Tree created successfully!" << std::endl;
}
