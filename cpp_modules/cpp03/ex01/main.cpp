#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "===== CLAPTRAP TESTS =====" << std::endl;
    ClapTrap clap("Clapper");

    std::cout << "\n===== CLAPTRAP COPY CONSTRUCTOR =====" << std::endl;
    ClapTrap clapCopy(clap);

    std::cout << "\n===== CLAPTRAP ASSIGNMENT =====" << std::endl;
    ClapTrap clapAssigned("Temp");
    clapAssigned = clap;

    std::cout << "\n===== CLAPTRAP BASIC ACTIONS =====" << std::endl;
    clap.attack("target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n===== SCAVTRAP CONSTRUCTION =====" << std::endl;
    ScavTrap scav("Scavver");

    std::cout << "\n===== SCAVTRAP COPY CONSTRUCTOR =====" << std::endl;
    ScavTrap scavCopy(scav);

    std::cout << "\n===== SCAVTRAP ASSIGNMENT =====" << std::endl;
    ScavTrap scavAssigned("Temporary");
    scavAssigned = scav;

    std::cout << "\n===== SCAVTRAP ATTACKS =====" << std::endl;
    scav.attack("enemy");
    scavCopy.attack("another enemy");

    std::cout << "\n===== SCAVTRAP SPECIAL ABILITY =====" << std::endl;
    scav.guardGate();
    scav.guardGate();
    scavCopy.guardGate();

    std::cout << "\n===== SCAVTRAP DAMAGE & REPAIR =====" << std::endl;
    scav.takeDamage(30);
    scav.beRepaired(20);

    std::cout << "\n===== SCAVTRAP ENERGY TEST (starts with 50) =====" << std::endl;
    for (int i = 0; i < 5; ++i)
        scavCopy.attack("test target");

    std::cout << "\n===== SCAVTRAP DEATH TEST =====" << std::endl;
    ScavTrap doomed("Doomed");
    doomed.takeDamage(50);
    doomed.takeDamage(50);
    doomed.attack("Someone");
    doomed.beRepaired(10);

    std::cout << "\n===== DESTRUCTION SEQUENCE =====" << std::endl;
    return 0;
}
