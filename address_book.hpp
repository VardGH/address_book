#ifndef ADDRESS_BOOK_HPP
#define ADDRESS_BOOK_HPP

#include "contact.hpp"

#include <fstream>
#include <iostream>
#include <vector>

class AddressBook
{
public:
    AddressBook() = default;

public:
    void display_all_contacts() const; // View all the contacts in the address book.
    void add_contact(); // Add a new contact with a name, surname, phone number, and email address.
    void remove_contact(const std::string&); // Remove an existing contact by name.
    void update_contact(const std::string&); // Update the information of an existing contact.
    void search_contacts(const std::string&) const; // Search for contacts by name.
    void load_from_file(const std::string&);
    void save_to_file(const std::string&) const;

private:
    std::vector<Contact> m_contacts;
};

#endif //ADDRESS_BOOK_HPP