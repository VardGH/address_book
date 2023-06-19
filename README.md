# Address Book

The Address Book program is a simple command-line application that allows users to manage their contacts. It provides functionality to add, remove, update, search, and display contacts.

## Features

- Add a new contact with a name, surname, phone number, and email address.
- Remove an existing contact by name.
- Update the information of an existing contact.
- Search for contacts by name.
- Display all contacts in the address book.

## Getting Started

1. Clone the repository or download the source code.
2. Compile the program using a C++ compiler (g++ *cpp).
3. Run the compiled executable file.

## Usage

1. Launch the program.
2. Choose an option from the menu:
   - Add a new contact: Enter the contact details when prompted.
   - Remove a contact: Enter the name of the contact to be removed.
   - Update a contact: Enter the name of the contact to be updated, and then provide the new details.
   - Search for contacts: Enter a name to search for matching contacts.
   - Display all contacts: View all the contacts in the address book.
   - Quit: Exit the program.
3. Follow the instructions provided by the program to perform the desired actions.

## File Management

The address book data is saved and loaded from a file named "contacts.txt" in the current working directory. When the program starts, it attempts to load the existing contacts from the file. When contacts are added, removed, or updated, the changes are automatically saved to the file.
