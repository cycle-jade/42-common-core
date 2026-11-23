#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    Weapon Gun("Bazooka");
    HumanA Edo("Edo", Gun);
    HumanB Osvaldo("Osvaldo");

    Edo.attack();
    Osvaldo.attack();
    Osvaldo.setWeapon(Gun);
    Gun.setType("Shotgun");
    Edo.attack();
    Osvaldo.attack();
    return 0;
}