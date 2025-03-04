#include "ScalarConverter.hpp"
int main(){
    std::cout << "\nInput: 42" << std::endl;
    ScalarConverter::convert("42");
    
    std::cout << "\nInput: -42" << std::endl;
    ScalarConverter::convert("-42");
    
    std::cout << "\nInput: 4.2f" << std::endl;
    ScalarConverter::convert("4.2f");
    
    std::cout << "\nInput: -4.2" << std::endl;
    ScalarConverter::convert("-4.2");
    
    std::cout << "\nInput: nan" << std::endl;
    ScalarConverter::convert("nan");
    
    std::cout << "\nInput: +inf" << std::endl;
    ScalarConverter::convert("+inf");
    
    std::cout << "\nInput: -inff" << std::endl;
    ScalarConverter::convert("-inff");
    
    std::cout << "\nInput: a" << std::endl;
    ScalarConverter::convert("a");
    
    std::cout << "\nInput: hello" << std::endl;
    ScalarConverter::convert("hello");
    
    // Edge cases
    std::cout << "\nInput: 9999999999999999999999" << std::endl;
    ScalarConverter::convert("9999999999999999999999");
    
    std::cout << "\nInput: -9999999999999999999999" << std::endl;
    ScalarConverter::convert("-9999999999999999999999");
    
    std::cout << "\nInput: 0" << std::endl;
    ScalarConverter::convert("0");
    
    std::cout << "\nInput: -0" << std::endl;
    ScalarConverter::convert("-0");
    
    std::cout << "\nInput: 1.7976931348623157e+308" << std::endl;
    ScalarConverter::convert("1.7976931348623157e+308");
    
    std::cout << "\nInput: -1.7976931348623157e+308" << std::endl;
    ScalarConverter::convert("-1.7976931348623157e+308");
    
    return 0;
}
