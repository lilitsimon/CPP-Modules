#include "Intern.hpp"

int main() {
    try {
        // Creating an intern
        Intern intern;
        
        // Valid forms
        AForm* form1 = intern.makeForm("robotomy request", "Bender");
        AForm* form2 = intern.makeForm("shrubbery creation", "Garden");
        AForm* form3 = intern.makeForm("presidential pardon", "Morty");
        
        // Invalid form
        AForm* invalidForm = intern.makeForm("coffee request", "Boss");
        
        // Clean up allocated forms
        delete form1;
        delete form2;
        delete form3;
        delete invalidForm;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
