#include "menu.hpp"
#include <limits>

Menu::Menu()
{
    m_address_book.load_from_file("contacts.txt");
}

void Menu::display_menu() const 
{
    std::cout << "---------------------------" << std::endl;
    std::cout << "|      Address Book        |" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "1. Display All Contacts    |" << std::endl;
    std::cout << "2. Add Contact             |" << std::endl;
    std::cout << "3. Remove Contact          |" << std::endl;
    std::cout << "4. Update Contact          |" << std::endl;
    std::cout << "5. Search Contacts         |" << std::endl;
    std::cout << "6. Quit                    |" << std::endl;
    std::cout << "---------------------------" << std::endl;
}

void Menu::play() 
{
    int choice;
    std::string search;

    while (true) {
        display_menu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                m_address_book.display_all_contacts();
                break;
            case 2:
                m_address_book.add_contact();
                break;
            case 3:
                std::cout << "Enter the name of the contact to remove: ";
                std::cin >> search;
                m_address_book.remove_contact(search);
                break;
            case 4:
                std::cout << "Enter the name of the contact to update: ";
                std::cin >> search;
                m_address_book.update_contact(search);
                break;
            case 5:
                std::cout << "Enter the name to search for: ";
                std::cin >> search;
                m_address_book.search_contacts(search);
                break;
            case 6:
                m_address_book.save_to_file("contacts.txt");
                std::cout << "Exiting the program." << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the input buffer
        std::cout << "---------------------------" << std::endl;
    }
}