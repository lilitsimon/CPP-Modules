#include "iter.hpp"

template <typename T>
void printElement(T &element) {
    std::cout << element << " ";
}


template <typename T>
void incrementElement(T &element) {
    element++;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
    iter(intArray, intArraySize, printElement);
    std::cout << std::endl;

    iter(intArray, intArraySize, incrementElement);
    
    std::cout << "Incremented int array: ";
    iter(intArray, intArraySize, printElement);
    std::cout << std::endl;

    std::string strArray[] = {"Hello", "World", "C++"};
    size_t strArraySize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array: ";
    iter(strArray, strArraySize, printElement);
    std::cout << std::endl;

    return 0;
}
