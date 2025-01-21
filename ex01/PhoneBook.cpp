#include "PhoneBook.hpp"
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : contact_count(0), oldest_index(0) {}

void PhoneBook::addContact(){
    if (contact_count < 8) {
        contacts[contact_count].setContactInfo();
        contact_count++;
    }
    else {
        std::cout << "Replacing the oldest contact." << std::endl;
        contacts[oldest_index].setContactInfo();
        oldest_index = (oldest_index + 1) % 8;
    }
}

void PhoneBook::displayContacts()const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(44, '-') << std::endl;
    for (int i = 0; i < contact_count; i++){
        contacts[i].displayContactSummary(i+1);
    }
}

void PhoneBook::displayContactDetails(int index) const{
    if (index < 1 || index > contact_count) {
        std::cout <<"Invalid index" << std::endl;
        return;
        contacts[index-1].displayContactDetails();
    }

}




