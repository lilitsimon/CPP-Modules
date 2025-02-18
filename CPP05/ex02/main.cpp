
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        // Creating Bureaucrats
        Bureaucrat alice("Alice", 140);
        Bureaucrat bob("Bob", 45);
        Bureaucrat charlie("Charlie", 5);

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << charlie << std::endl;

        // Creating Forms
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Fry");

        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        // Signing and executing ShrubberyCreationForm
        alice.signForm(shrubbery);
        alice.executeForm(shrubbery);
        
        // Signing and executing RobotomyRequestForm
        bob.signForm(robotomy);
        bob.executeForm(robotomy);
        
        // Signing and executing PresidentialPardonForm
        charlie.signForm(pardon);
        charlie.executeForm(pardon);
        
        // Failure cases
        Bureaucrat dave("Dave", 150);
        std::cout << dave << std::endl;
        dave.signForm(shrubbery); // Should fail
        dave.executeForm(shrubbery); // Should fail

        Bureaucrat eve("Eve", 50);
        eve.signForm(robotomy);
        eve.executeForm(robotomy); // Should fail (too low)
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
