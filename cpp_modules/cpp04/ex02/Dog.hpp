#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
protected:
    Brain *brain;

public:
    Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    void makeSound() const;
    ~Dog();

    void setBrainIdea(int index, const std::string &idea);
    std::string getBrainIdea(int index) const;
};