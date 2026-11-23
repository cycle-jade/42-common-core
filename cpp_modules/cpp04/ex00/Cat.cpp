#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
}
Cat::Cat(const Cat& other) : Animal(other) 
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assignment operator function called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

Cat::~Cat() 
{
    std::cout << "Cat destructor called" << std::endl;
}