#include "address_book.hpp"

void AddressBook::display_all_contacts() const
{
    if (m_contacts.empty()) {
        std::cout << "No contacts found in the address book!" << std::endl;
        return;
    }

    for (int i = 0; i < m_contacts.size(); ++i) {
        std::cout << "Name: " << m_contacts[i].get_name() << std::endl;
        std::cout << "Surname: " << m_contacts[i].get_surname() << std::endl;
        std::cout << "Phone Number: " << m_contacts[i].get_phone_number() << std::endl;
        std::cout << "Email: " << m_contacts[i].get_email() << std::endl;
        std::cout << std::endl;
    }
}

void AddressBook::add_contact()
{
    Contact new_contatct;

    std::string new_name = "";
    std::cout << "Please enter a name : ";
    std::cin >> new_name;
    new_contatct.set_name(new_name);

    std::string new_suranme = "";
    std::cout << "Please enter a surname: ";
    std::cin >> new_suranme;
    new_contatct.set_surname(new_suranme);

    std::string new_phone_number = "";
    std::cout << "Please enter a phone number: ";
    std::cin >> new_phone_number;
    new_contatct.set_phone_number(new_phone_number);

    std::string new_email = "";
    std::cout << "Please enter an email: ";
    std::cin >> new_email;
    new_contatct.set_email(new_email);

    m_contacts.push_back(new_contatct);
    std::cout << "Contact added successfully." << std::endl;

    save_to_file("contacts.txt");
}

void AddressBook::save_to_file(const std::string& filename) const
{
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to create file: " << filename << std::endl;
        return;
    }

    for (const auto& contact : m_contacts) {
        file << contact.get_name() << std::endl;
        file << contact.get_surname() << std::endl;
        file << contact.get_phone_number() << std::endl;
        file << contact.get_email() << std::endl;
        file << std::endl;
    }

    file.close();
    std::cout << "Address book saved to file: " << filename << std::endl;
}


void AddressBook::load_from_file(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return;
    }

    m_contacts.clear();

    std::string name;
    std::string surname;
    std::string phone_number;
    std::string email;

    while (file >> name >> surname >> phone_number >> email) {
        Contact new_contact(name, surname, phone_number, email);
        m_contacts.push_back(new_contact);
    }

    file.close();
    std::cout << "Address book loaded from file: " << filename << std::endl;
}

void AddressBook::remove_contact(const std::string& name)
{
    bool found = false;
    for (int i = 0; i < m_contacts.size(); ++i) {
        if (m_contacts[i].get_name() == name) {
            found = true;
            m_contacts.erase(m_contacts.begin() + i);
            std::cout << "Contact removed successfully." << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Contact with name " << name << " not found." << std::endl;
    }

    save_to_file("contacts.txt");
}

void AddressBook::update_contact(const std::string& name)
{
    bool found = false;
    for (int i = 0; i < m_contacts.size(); ++i) {
        if (m_contacts[i].get_name() == name) {
            std::string new_name;
            std::cout << "Enter new name: ";
            std::cin >> new_name;
            m_contacts[i].set_name(new_name);

            std::string new_surname;
            std::cout << "Enter new surname: ";
            std::cin >> new_surname;
            m_contacts[i].set_surname(new_surname);

            std::string new_phone;
            std::cout << "Enter new phone number: ";
            std::cin >> new_phone;
            m_contacts[i].set_phone_number(new_phone);

            std::string new_email;
            std::cout << "Enter new email: ";
            std::cin >> new_email;
            m_contacts[i].set_email(new_email);

            std::cout << "Contact updated successfully." << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Contact with name " << name << " not found." << std::endl;
    }

    save_to_file("contacts.txt");
}

void AddressBook::search_contacts(const std::string& name) const
{
    bool found = false;
    for (int i = 0; i < m_contacts.size(); ++i) {
        if (m_contacts[i].get_name() == name) {
            std::cout << "Name: " << m_contacts[i].get_name() << std::endl;
            std::cout << "Surname: " << m_contacts[i].get_surname() << std::endl;
            std::cout << "Phone Number: " << m_contacts[i].get_phone_number() << std::endl;
            std::cout << "Email: " << m_contacts[i].get_email() << std::endl;
            std::cout << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No contacts found with name " << name << std::endl;
    }
}