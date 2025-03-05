#include "Identifier.hpp"

Base* generate() {
    std::srand(std::time(0)); // std::tme(0) - returns the current time in seconds, and since it's different, the seed is different. srand sets the seed for std::rand(), ensuring different random sequences. We ddo this so that the random numbers are different every time
    int choice = std::rand() % 3;
    switch (choice) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return NULL;
}

void identify(Base* p) {
    if (!p) {
        std::cout << "Null pointer received" << std::endl;
        return;
    }

    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else 
        std::cout << "Unknown Type" << std::endl;
}


void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p); // We don’t need the reference, so (void) tells the compiler we’re intentionally ignoring it.
        std::cout << "A" << std::endl;
        return;
    }
    catch(...) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch(...) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch(...) {}
    std::cout << "Unknown Type" << std::endl;
}
