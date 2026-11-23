#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal
{
protected:
    Brain *brain;

public:
    Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    void makeSound() const;
    ~Cat();

    void setBrainIdea(int index, const std::string &idea);
    std::string getBrainIdea(int index) const;
};
