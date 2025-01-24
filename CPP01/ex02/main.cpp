#include <string>
#include <iostream>

int main(){
    std::string myString = "HI THIS IS BRAIN";
    std::string *stringPTR = &myString;
    std::string &stringREF = myString;

    std::cout << "Memory address of the string variable: " << &myString << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by strREF: " << &stringREF << std::endl;

    std::cout << "Value of the string variable: " << myString << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}
