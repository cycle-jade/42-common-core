#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "===== CLAPTRAP TESTS =====" << std::endl;
    ClapTrap clap("Clapper");
    clap.attack("target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n===== SCAVTRAP CONSTRUCTION =====" << std::endl;
    ScavTrap scav("Scavvy");

    std::cout << "\n===== SCAVTRAP COPY & ASSIGNMENT =====" << std::endl;
    ScavTrap scavCopy(scav);
    ScavTrap scavAssigned("ScavTemp");
    scavAssigned = scav;

    std::cout << "\n===== SCAVTRAP ATTACKS & ABILITIES =====" << std::endl;
    scav.attack("enemy");
    scav.guardGate();
    scav.takeDamage(40);
    scav.beRepaired(25);

    std::cout << "\n===== FRAGTRAP CONSTRUCTION =====" << std::endl;
    FragTrap frag("Fragger");

    std::cout << "\n===== FRAGTRAP COPY CONSTRUCTOR =====" << std::endl;
    FragTrap fragCopy(frag);

    std::cout << "\n===== FRAGTRAP ASSIGNMENT =====" << std::endl;
    FragTrap fragAssigned("FragTemp");
    fragAssigned = frag;

    std::cout << "\n===== FRAGTRAP ATTACKS & ABILITIES =====" << std::endl;
    frag.attack("target");
    fragCopy.attack("another target");
    frag.highFivesGuys();
    fragCopy.highFivesGuys();

    std::cout << "\n===== FRAGTRAP DAMAGE & REPAIR =====" << std::endl;
    frag.takeDamage(50);
    frag.beRepaired(30);

    std::cout << "\n===== FRAGTRAP ENERGY TEST (starts with 100) =====" << std::endl;
    for (int i = 0; i < 5; ++i)
        fragAssigned.attack("dummy");

    std::cout << "\n===== FRAGTRAP DEATH TEST =====" << std::endl;
    FragTrap doomed("Doomed");
    doomed.takeDamage(60);
    doomed.takeDamage(40);
    doomed.attack("Someone");
    doomed.beRepaired(20);

    std::cout << "\n===== DESTRUCTION SEQUENCE =====" << std::endl;
    return 0;
}
