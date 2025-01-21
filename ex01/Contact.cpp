#include "Contact.hpp"
#include <iomanip> // for setw - formats the output


void Contact::setContactInfo(){
    while(true){
        std::cout << "Enter first name: " << std::endl;
        std::getline(std::cin, first_name); // reads the characters one by one and stores int he first_name
        if (!first_name.empty() && std::all_of(first_name.begin(), first_name.end(), [](char c){
            return std::isalpha(c) || std::isspace(c) || c == '-';
            }) )
            break;
    std::cout << "Invalid input. Please enter alphabetic characters, spaces or hyphens." << std::endl;
    }

    while(true){
        std::cout << "Enter last name " << std::endl;
        std::getline(std::cin, last_name);
        if(!last_name.empty() && std::all_of(last_name.begin(), last_name.end(), [](char c) {
            return std::isalpha(c) || std::isspace(c) || c == '-';
        }))
            break;
        std::cout << "Invalid input. Please enter alphabetic characters, spaces or hyphens." << std::endl;
    }

    while (true){
        std::cout << "Enter nickname " << std::endl;
        std::getline(std::cin, nickname);
        if(!nickname.empty())
            break;
        std::cout << "Invalid Input. Please Enter a valid nickname." << std::endl;
    }
        
    while(true){
        std::cout << "Enter phone number " << std::endl;
        std::getline(std::cin, phone_number);
        if(!phone_number.empty() && std::all_of(phone_number.begin(), phone_number.end(), [](char c) {
            return std::isdigit(c);
        }))
            break;
        std::cout << "Invalid input. Please enter only numeric numbers." << std::endl;
    }
        
    while(true) {
        std::cout << "Enter darkest secret " << std::endl;
        std::getline(std::cin, darkest_secret);
        if (!darkest_secret.empty())
            break;
        std::cout << "Invalid input. Please enter a valid secret." << std::endl;
    }
}

void Contact::displayContactSummary(int index) const {
    //lambda function. [] is the capture clause, &str is the parameter, & means access directly the paramter and -> is the return type
    auto truncate = [](const std::string &str) -> std::string {
       if (str.length() > 10) {
            return str.substr(0, 9) + ".";
       }
        else
            return str;
    };
    std::cout << std::setw(10) << index << "|"
        << std::setw(10) << truncate(first_name) << "|"
        << std::setw(10) << truncate(last_name) << "|"
        << std:: setw(10) << truncate(nickname) << std::endl;
}


void Contact::displayContactDetails() const {
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

