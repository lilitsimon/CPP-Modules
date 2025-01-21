#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>


void Contact::setContactInfo(){
    char c;

    while(true){
        bool is_valid = true;
        std::cout << "Enter the first name: " << std::endl;
        if(!std::getline(std::cin, first_name))
            exit(1);
        for (size_t i = 0; i < first_name.length(); ++i) {
            c = first_name[i];
            if (!(std::isalpha(c) || std::isspace(c) || c == '-')) {
                is_valid = false;
                break;
            }
        }
        if (!first_name.empty() && is_valid) {
            break;
        }
    std::cout << "Invalid input. Please enter alphabetic characters, spaces or hyphens." << std::endl;
    }

    while(true){
        bool is_valid = true;
        std::cout << "Enter the last name: " << std::endl;
        if(!std::getline(std::cin, last_name))
            exit(1);
        for (size_t i = 0; i < last_name.length(); ++i) {
            c = last_name[i];
            if (!(std::isalpha(c) || std::isspace(c) || c == '-')) {
                is_valid = false;
                break;
            }
        }
        if (!last_name.empty() && is_valid) {
            break;
        }
    std::cout << "Invalid input. Please enter alphabetic characters, spaces or hyphens." << std::endl;
    }

    while (true){
        std::cout << "Enter the nickname: " << std::endl;
        if(!std::getline(std::cin, nickname))
            exit(1);
        if(!nickname.empty())
            break;
        std::cout << "Invalid Input. Please Enter a valid nickname." << std::endl;
    }
        
    while(true){
        bool is_valid = true;
        std::cout << "Enter the phone number: " << std::endl;
        if(!std::getline(std::cin, phone_number))
            exit(1);
        for (size_t i = 0; i < phone_number.length(); ++i) {
            c = phone_number[i];
            if (!(std::isdigit(c) )) {
                is_valid = false;
                break;
            }
        }
        if (!phone_number.empty() && is_valid) {
            break;
        }
        std::cout << "Invalid input. Please enter only numeric numbers." << std::endl;
    }
        
    while(true) {
        std::cout << "Enter the darkest secret: " << std::endl;
        if(!std::getline(std::cin, darkest_secret))
            exit(1);
        if (!darkest_secret.empty())
            break;
        std::cout << "Invalid input. Please enter a valid secret." << std::endl;
    }
    std::cout << "Contact created successfully!" << std::endl;
}

std::string truncate_string (const std::string &str, size_t width){
    if (str.length() > width) 
        return str.substr(0, width - 1) + ".";
    return str;
}

void Contact::displayContactSummary(int index) const {
    std::cout << std::setw(10) << index << "|"
        << std::setw(10) << truncate_string(first_name, 10) << "|"
        << std::setw(10) << truncate_string(last_name, 10) << "|"
        << std:: setw(10) << truncate_string(nickname, 10) << std::endl;
}


void Contact::displayContactDetails() const {
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

