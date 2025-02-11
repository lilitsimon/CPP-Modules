#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat high("Alice", 1);
        Bureaucrat low("Bob", 150);
        std::cout << high << std::endl;
        std::cout << low << std::endl;

        high.incrementGrade(); //  exception
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalid("Charlie", 0); //exception
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat middle("David", 75);
        std::cout << middle << std::endl;
        middle.incrementGrade();
        std::cout << "After increment: " << middle << std::endl;
        middle.decrementGrade();
        std::cout << "After decrement: " << middle << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat top("Eve", 2);
        std::cout << top << std::endl;
        top.incrementGrade();
        std::cout << "After increment: " << top << std::endl;
        top.incrementGrade(); // exception
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bottom("Frank", 149);
        std::cout << bottom << std::endl;
        bottom.decrementGrade();
        std::cout << "After decrement: " << bottom << std::endl;
        bottom.decrementGrade(); // exception
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}


