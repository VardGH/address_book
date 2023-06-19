#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact 
{
public:
    Contact();
    Contact(const std::string& name, const std::string& surname, std::string& phone_number, std::string& email);

public:
    // getters
    std::string get_name() const;
    std::string get_surname() const;
    std::string get_phone_number() const;
    std::string get_email() const;

    // setters
    void set_name(const std::string&);
    void set_surname(const std::string&);
    void set_phone_number(std::string&);
    void set_email(std::string&);

private:
    bool is_valid_phone_number(const std::string&) const;
    bool is_valid_email(const std::string&) const;
    bool is_digit(const char) const;
    bool is_char(const char) const;

private:
    std::string m_name;
    std::string m_surname;
    std::string m_phone_number;
    std::string m_email;
};

#endif //CONTACT_HPP