
#include "ScalarConverter.hpp"
void ScalarConverter::convert(const std::string& input) {
    double doubleValue;
    char charValue;
    int intValue;
    float floatValue;

    if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0])) {
        charValue = input[0];
        intValue = static_cast<int>(charValue);
        floatValue = static_cast<float>(intValue);
        doubleValue = static_cast<double>(intValue);

        std::cout << "char: '" << charValue << "'" << std::endl;
        std::cout << "int: " << intValue << std::endl;
        std::cout << "float: " << floatValue << "f" << std::endl;
        std::cout << "double: " << doubleValue << std::endl;
        return;
    }

    if (input == "nan" || input == "nanf" || input == "-inf" || input == "+inf" || input == "-inff" || input == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input;
        if (input.back() != 'f')
            std::cout << "f";
        std::cout << std::endl;
        std::cout << "double: " << (input.back() == 'f' ? input.substr(0, input.size() - 1) : input) << std::endl;
        return;
    }

    char* end;
    doubleValue = std::strtod(input.c_str(), &end); // // converts the std::string into a C-style string (const char*), required by strtod(), end is to store hte remaining characters
    if (*end != '\0') {
        std::cout << "Invalid input." << std::endl;
        return;
    }

    intValue = static_cast<int>(doubleValue); // Explicitly casts doubleValue to int using static_cast<int>(). This truncates the decimal part (does not round).
    floatValue = static_cast<float>(doubleValue);
    charValue = static_cast<char>(intValue);

    if (std::isprint(charValue) && doubleValue >= 0 && doubleValue <= 127)
        std::cout << "char: '" << charValue << "'" << std::endl;
    else if (doubleValue < 0 || doubleValue > 127)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (doubleValue > std::numeric_limits<int>::max() || doubleValue < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << intValue << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << floatValue << "f" << std::endl;
    std::cout << "double: " << doubleValue << std::endl;
}
