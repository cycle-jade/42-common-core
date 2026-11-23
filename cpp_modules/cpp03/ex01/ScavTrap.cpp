#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default_Scav")
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    gateKeeping = false;
    std::cout << "ScavTrap " << name << " created" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    gateKeeping = false;
    std::cout << "ScavTrap " << this->name << " created" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    this->gateKeeping = other.gateKeeping;
    std::cout << "ScavTrap " << name << " copied" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "ScavTrap " << name << " assigned" << std::endl;
    return *this;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " destroyed" << std::endl;
}
void ScavTrap::guardGate()
{
	if (this->gateKeeping)
		return;
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
	this->gateKeeping = true;
}
void ScavTrap::attack(const std::string &target)
{
    std::cout << "ScavTrap " << name << " attacks " << target
              << ", causing " << attackDamage
              << " points of damage!" << std::endl;
}
