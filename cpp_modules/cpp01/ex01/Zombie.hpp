#pragma once
#include <string>
#include <iostream>

class Zombie
{
private:
    std::string name;
public:
    Zombie();
    void announce();
    void setName(std::string zombie_name);
    ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);