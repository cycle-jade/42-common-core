#include "Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
    std::cout << "Dog constructor called" << std::endl;
    brain = new Brain();
    this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other) 
{
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
    type = other.type;
}


Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignment operator function called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *this->brain = *other.brain;
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
    delete brain;
}
void Dog::setBrainIdea(int index, const std::string &idea)
{
    brain->setIdea(index, idea);
}
std::string Dog::getBrainIdea(int index) const
{
    return brain->getIdea(index);
}