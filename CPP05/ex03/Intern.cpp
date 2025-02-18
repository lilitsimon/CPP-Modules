#include "Intern.hpp"
#include "iostream"

Intern::Intern(){}
Intern::Intern(const Intern& other) { 
    (void)other; // as it doesn't have any attributes, so nothing to copy;
}

Intern& Intern::operator=(const Intern& other){
    (void)other;
    return *this;
}
Intern::~Intern(){}

AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* forms[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };
    for (int i = 0; i < 3; i++){
        if (formName == formNames[i]){
            std::cout << "Intern creates " << formName << std::endl;
            for (int j = 0; j < 3; j++) {
                if (j != i)
                    delete forms[j]; //cleaning unsused forms
            return forms[i];
            }
        }
    }
    std::cout << "Error: Unknown form type '" << formName << "'" << std::endl;
    for (int i = 0; i < 3; i++) {
        delete forms[i]; 
    } // Clean up all forms
    return NULL;
}

