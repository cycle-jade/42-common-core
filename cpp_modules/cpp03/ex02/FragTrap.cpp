#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default_Frag")
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " created" << std::endl;
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << this->name << " created" << std::endl;
}
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    std::cout << "FragTrap " << name << " copied" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap " << name << " assigned" << std::endl;
    return *this;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destroyed" << std::endl;
}
void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " is requesting a high five!" << std::endl;
}
void FragTrap::attack(const std::string &target)
{
    std::cout << "FragTrap " << name << " attacks " << target
              << ", causing " << attackDamage
              << " points of damage!" << std::endl;
}