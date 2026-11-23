#include "HumanB.hpp"
HumanB::HumanB(const std::string &humanName) : name(humanName), weapon(NULL) 
{
    std::cout << "HumanB " << name << " created." << std::endl;
}

HumanB::~HumanB() 
{
    std::cout << "HumanB " << name << " destroyed." << std::endl;
}

void HumanB::setWeapon(Weapon &humanWeapon)
{
    weapon = &humanWeapon;
}
void HumanB::attack() const
{
    if (weapon)
        std::cout << name << " attacks with the " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with!" << std::endl;
}