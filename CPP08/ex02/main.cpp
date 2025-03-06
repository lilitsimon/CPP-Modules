#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
    std::cout << "Testing MutantStack...\n";
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;
    
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Iterating through MutantStack:\n";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "Copying MutantStack to std::stack...\n";
    std::stack<int> s(mstack);

    // Compare with std::list
    std::cout << "Testing std::list (same operations)...\n";
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.pop_back();
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "Iterating through list:\n";
    for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit) {
        std::cout << *lit << std::endl;
    }

    return 0;
}
