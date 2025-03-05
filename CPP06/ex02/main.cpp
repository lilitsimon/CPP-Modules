#include "Identifier.hpp"

int main() {
    Base* instance = generate();
    std::cout << "Identifying via pointer: ";
    identify(instance);
    std::cout << "Identifying via reference: ";
    identify(*instance);
    delete instance;
    return 0;
}
