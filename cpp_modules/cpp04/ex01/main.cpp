#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int size = 4;
    const Animal* animals[size];

    for (int i = 0; i < size / 2; ++i)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; ++i)
        animals[i] = new Cat();

    std::cout << "---- Sounds ----" << std::endl;
    for (int i = 0; i < size; ++i)
        animals[i]->makeSound();

    std::cout << "---- Deleting ----" << std::endl;
    for (int i = 0; i < size; ++i)
        delete animals[i]; 

    std::cout << "---- Deep copy test ----" << std::endl;
    Dog dog1;
    dog1.setBrainIdea(0, "Chase the cat");

    Dog dog2 = dog1;
    std::cout << "dog1 idea: " << dog1.getBrainIdea(0) << std::endl;
    std::cout << "dog2 idea: " << dog2.getBrainIdea(0) << std::endl;

    dog2.setBrainIdea(0, "Eat food");

    std::cout << "After change:" << std::endl;
    std::cout << "dog1 idea: " << dog1.getBrainIdea(0) << std::endl;
    std::cout << "dog2 idea: " << dog2.getBrainIdea(0) << std::endl;

    return 0;
}