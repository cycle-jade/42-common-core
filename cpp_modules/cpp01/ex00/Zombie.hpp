#pragma once
#include <string>
#include <iostream>

class Zombie
{
private:
    std::string name;
public:
    Zombie(std::string zombie_name);
    void announce();
    ~Zombie();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);