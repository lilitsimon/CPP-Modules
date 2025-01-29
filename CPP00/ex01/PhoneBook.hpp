#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

private:
    Contact contacts[8]; // array of objects
    int contact_count;
    int oldest_index;
public:
    PhoneBook(); // constructor - initializes the PhoneBook object, sets the count and index to 0
    void addContact();
    bool displayContacts() const;
    bool displayContactDetails(int index) const; 

};

#endif
