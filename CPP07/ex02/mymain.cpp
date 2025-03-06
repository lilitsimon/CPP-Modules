#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 10  // Keeping it small for easier debugging

int main() {
    std::cout << "Creating an array of size " << MAX_VAL << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    std::srand(std::time(NULL));

    // Filling arrays with random values
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = std::rand() % 100;  // Random value between 0-99
        numbers[i] = value;
        mirror[i] = value;
    }

    // Checking that values match
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "Error: Values don't match at index " << i << std::endl;
            delete[] mirror;
            return 1;
        }
    }
    std::cout << "All values correctly stored and retrieved.\n";

    // Testing copy constructor
    std::cout << "Testing copy constructor...\n";
    Array<int> copyArray(numbers);
    for (int i = 0; i < MAX_VAL; i++) {
        if (copyArray[i] != numbers[i]) {
            std::cerr << "Error: Copy constructor failed at index " << i << std::endl;
            delete[] mirror;
            return 1;
        }
    }
    std::cout << "Copy constructor works correctly.\n";

    // Testing assignment operator
    std::cout << "Testing assignment operator...\n";
    Array<int> assignedArray;
    assignedArray = numbers;
    for (int i = 0; i < MAX_VAL; i++) {
        if (assignedArray[i] != numbers[i]) {
            std::cerr << "Error: Assignment operator failed at index " << i << std::endl;
            delete[] mirror;
            return 1;
        }
    }
    std::cout << "Assignment operator works correctly.\n";

    // Testing out-of-bounds exception handling
    std::cout << "Testing out-of-bounds access...\n";
    try {
        numbers[-1] = 42;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception (negative index): " << e.what() << std::endl;
    }

    try {
        numbers[MAX_VAL] = 42;  // Out of bounds
    } catch (const std::exception& e) {
        std::cerr << "Caught exception (too large index): " << e.what() << std::endl;
    }

    // Testing modification
    std::cout << "Modifying array...\n";
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = i * 10;
    }
    std::cout << "Modified values:\n";
    for (int i = 0; i < MAX_VAL; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    delete[] mirror;  // Free allocated memory

    std::cout << "All tests passed successfully!\n";
    return 0;
}
