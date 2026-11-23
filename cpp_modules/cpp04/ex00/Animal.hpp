#pragma once
#include <string>
#include <iostream>

class Animal 
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const std::string& type);
        Animal& operator=(const Animal& other);
        virtual void makeSound() const;
        std::string getType() const;
        virtual ~Animal();
};