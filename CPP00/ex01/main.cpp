#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int stringToInt(const std::string &str) {
    int result = 0;
    if (str.empty())
        throw std::invalid_argument("Empty input is not a valid integer.");
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i]))
            throw std::invalid_argument("Invalid character in input.");
        result = result * 10 + (str[i] - '0');
    }

    return result;
}

int main(){
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter a Command (ADD, SEARCH, EXIT): " << std::endl;
        if (!std::getline(std::cin, command))
            break;

        if (command == "ADD") 
            phonebook.addContact();
        else if (command == "SEARCH") {
                if(phonebook.displayContacts()){
                    while(true){
                        std::cout << "Enter the index of the contact to view details: " << std::endl;
                        std::string index_input;
                        if(!std::getline(std::cin, index_input))
                            break;
                        try {
                            int index = stringToInt(index_input);
                            if(phonebook.displayContactDetails(index))
                                break;
                        }
                        catch (const std::exception &) {
                            std::cout << "Invalid input. Please enter a numeric index." << std::endl;
                        }
                    }
                }
            }
        else if (command == "EXIT") {
            std::cout << "Exiting Phonebook." << std::endl;
            break;
        }
        else
            std::cout << "Invalid command. Please enter ADD, SEARCH or EXIT." << std::endl;
    }
    return 0;
}
