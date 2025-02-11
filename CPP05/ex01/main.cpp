#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        // Case 1: Bureaucrat with too low grade to sign
        Bureaucrat alice("Alice", 50);
        Form A1("A1", 40, 20);
        std::cout << A1 << std::endl;
        alice.signForm(A1);
        std::cout << A1 << std::endl;

        // Case 2: Bureaucrat with exact grade required to sign
        Bureaucrat bob("Bob", 40);
        Form B1("B1", 40, 20);
        std::cout << B1 << std::endl;
        bob.signForm(B1);
        std::cout << B1 << std::endl;

        // Case 3: Bureaucrat with higher grade than required (successful sign)
        Bureaucrat charlie("Charlie", 30);
        Form C1("C1", 35, 10);
        std::cout << C1 << std::endl;
        charlie.signForm(C1);
        std::cout << C1 << std::endl;

        // Case 4: Bureaucrat with too high a grade (exception in constructor)
        try {
            Form invalidForm("InvalidForm", 0, 10); // Grade too high
        } catch (std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Case 5: Bureaucrat with too low a grade (exception in constructor)
        try {
            Form invalidForm("InvalidForm", 151, 10); // Grade too low
        } catch (std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}


