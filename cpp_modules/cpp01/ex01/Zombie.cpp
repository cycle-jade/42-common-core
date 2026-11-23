#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "Default Zombiecreated." << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << name << " destroyed." << std::endl;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string zombie_name) {
    name = zombie_name;
}