#include "Weapon.hpp"

Weapon::Weapon(const std::string& weaponType): type(weaponType) { std::cout << "Weapon " << type << " created." << std::endl; };
void Weapon::setType(const std::string& weaponType) { type = weaponType; };
const std::string& Weapon::getType() const { return type; };
Weapon::~Weapon() { std::cout << std::endl << "Weapon " << type << " destroyed." << std::endl; };
