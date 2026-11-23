#include "phonebook.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;
    std::cout << "Welcome to your PhoneBook!" << std::endl;
    while (1)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
            break;
        if (command == "ADD" || command == "1")
            phonebook.add_contact();
        else if (command == "SEARCH")
            phonebook.search_contact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command. Please try again." << std::endl;
    }

    return (0);
}