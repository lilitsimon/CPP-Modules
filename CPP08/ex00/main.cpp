#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
    try {

        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        vec.push_back(50);
        std::cout << "Vector test: Found value -> " << *easyfind(vec, 30) << std::endl;

        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(15);
        lst.push_back(25);
        lst.push_back(35);
        lst.push_back(45);
        std::cout << "List test: Found value -> " << *easyfind(lst, 25) << std::endl;

        std::cout << "Trying to find 100 in vector..." << std::endl;
        std::cout << *easyfind(vec, 100) << std::endl; // Should throw an exception

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
