#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include "address_book.hpp"

class Menu 
{
public:
    Menu();
public:
    void play();
    void display_menu() const;
private:
    AddressBook m_address_book;
};

#endif // MENU_HPP