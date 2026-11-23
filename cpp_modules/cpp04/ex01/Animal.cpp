#include "Animal.hpp"

Animal::Animal() : type("Animal") 
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string& type) : type(type) 
{
    std::cout << "Animal constructor called" << std::endl;
}


Animal& Animal::operator=(const Animal& other)
{
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "* Generic animal sound *" << std::endl;
}

Animal::~Animal() 
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}