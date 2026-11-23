#pragma once
#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include  <cctype>

class PhoneBook 
{
    private:
    Contact list[8];
    int current_index;
    int size;

    public:
    PhoneBook();
    void    add_contact();
    void    search_contact();
    ~PhoneBook();
};