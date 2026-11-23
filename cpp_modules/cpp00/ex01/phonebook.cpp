#include "phonebook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : current_index(0), size(0) { std::cout << "PhoneBook created." << std::endl; }
PhoneBook:: ~PhoneBook() { std::cout << "PhoneBook destroyed." << std::endl; }

void PhoneBook::add_contact()
{
    Contact new_contact;
    std::string input;

    while (input.empty())
    {
        std::cout << "Enter Name: ";
        if (!std::getline(std::cin, input))
            return;
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
    new_contact.setname(input);
    input.clear();
    while (input.empty())
    {
        std::cout << "Enter Lastname: ";
        if (!std::getline(std::cin, input))
            return;
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
    new_contact.setlastname(input);
    input.clear();
    while (input.empty())
    {
        std::cout << "Enter Nickname: ";
        if (!std::getline(std::cin, input))
            return;
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
    new_contact.setnickname(input);
    input.clear();
    while (input.empty())
    {
        std::cout << "Enter Phone Number: ";
        if (!std::getline(std::cin, input))
            return;
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
    new_contact.setphonenumber(input);
    input.clear();
    while (input.empty())
    {
        std::cout << "Enter Darkest Secret: ";
        if (!std::getline(std::cin, input))
            return;
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
    new_contact.setdarkestsecret(input);
    list[current_index] = new_contact;
    current_index = (current_index + 1) % 8;
    if (size < 8)
        size++;
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::search_contact()
{
    int i = 0;
    if (size == 0)
    {
        std::cout << "PhoneBook is empty. No contacts to display." << std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    std::string input;
    int index = -1;
    while (i < size)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << (list[i].getname().length() > 10 ? list[i].getname().substr(0, 9) + "." : list[i].getname()) << "|"
                  << std::setw(10) << (list[i].getlastname().length() > 10 ? list[i].getlastname().substr(0, 9) + "." : list[i].getlastname()) << "|"
                  << std::setw(10) << (list[i].getnickname().length() > 10 ? list[i].getnickname().substr(0, 9) + "." : list[i].getnickname()) << std::endl;
        i++;
    }
    while (index < 0 || index >= size)
    {
        std::cout << "Enter the index of the contact to view details: ";
        if (!std::getline(std::cin, input))
            return;

        if (input.length() == 1 && std::isdigit(static_cast<unsigned char>(input[0])))
            index = input[0] - '0';
        else
            index = -1;

        if (index < 0 || index >= size)
            std::cout << "Invalid index. Please try again." << std::endl;
    }

    std::cout << "Name: " << list[index].getname() << std::endl;
    std::cout << "Last Name: " << list[index].getlastname() << std::endl;
    std::cout << "Nickname: " << list[index].getnickname() << std::endl;
    std::cout << "Phone Number: " << list[index].getphonenumber() << std::endl;
    std::cout << "Darkest secret: " << list[index].getdarkestsecret() << std::endl;
}