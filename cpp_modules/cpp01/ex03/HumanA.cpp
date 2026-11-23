#include "HumanA.hpp"

HumanA::HumanA(const std::string& humanName, Weapon& humanWeapon): name(humanName), weapon(humanWeapon) 
{
    std::cout << "HumanA " << name << " created." << std::endl;
}

void HumanA::attack() const
{
    std::cout << name << " attacks with the " << weapon.getType() << std::endl;
}
HumanA::~HumanA() 
{
    std::cout << "HumanA " << name << " destroyed." << std::endl;
}