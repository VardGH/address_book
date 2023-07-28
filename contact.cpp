#include "contact.hpp"
#include <iostream>

Contact::Contact()
    : m_name("")
    , m_surname("")
    , m_phone_number("")
    , m_email("")
{
}

Contact::Contact(const std::string& name, const std::string& surname, std::string& phone_number, std::string& email)
{
    set_name(name);
    set_surname(surname);
    set_phone_number(phone_number);
    set_email(email);
}

std::string Contact::get_name() const
{
    return m_name;
}

std::string Contact::get_surname() const
{
    return m_surname;
}

std::string Contact::get_phone_number() const
{
    return m_phone_number;
}

std::string Contact::get_email() const
{
    return m_email;
}

void Contact::set_name(const std::string& name)
{
    m_name = name;
}

void Contact::set_surname(const std::string& surname)
{
    m_surname = surname;
}

bool Contact::is_digit(const char c) const
{
    return (c >= '0' && c <= '9');
}

bool Contact::is_valid_phone_number(const std::string& phone_number) const 
{
    if (phone_number[0] != '0') {
        return false;
    }

    if (phone_number.length() != 9) {
        return false;
    }

    for (int i = 0; i < phone_number.length(); ++i) {
        if (!is_digit(phone_number[i])) {
            return false;
        }
    }

    return true;
}

void Contact::set_phone_number(std::string& phone_number)
{
    while (!is_valid_phone_number(phone_number)) {
        std::cout << "Invalid phone number. Please enter a valid phone number: ";
        phone_number = "";
        std::cin >> phone_number;
    }
    m_phone_number = phone_number;
}

bool Contact::is_char(const char c) const
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool Contact::is_valid_email(const std::string& email) const
{
    if (!is_char(email[0])) {
        return false;
    }
    
    int at = -1;
    int dot = -1;
    
    for (int i = 0; i < email.length(); ++i) {
        if (email[i] == '@') {
            at = i;
        } else if (email[i] == '.') {
            dot = i;
        }
    }
    
    if (at == -1 || dot == -1) {
        return false;
    }
        
    if (at > dot) {
        return false;
    }
        
    return !(dot >= (email.length() - 1));
}

void Contact::set_email(std::string& email)
{
    while (!is_valid_email(email)) {
        std::cout << "Invalid email address. Please enter a valid email address: ";
        email = "";
        std::cin >> email;
    }
    m_email = email;
}