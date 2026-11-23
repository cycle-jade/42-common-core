#include "Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other) 
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}


Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignment operator function called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}

Dog::~Dog() 
{
    std::cout << "Dog destructor called" << std::endl;
}