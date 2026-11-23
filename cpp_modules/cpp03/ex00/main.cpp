#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "===== BASIC CONSTRUCTION =====" << std::endl;
    ClapTrap a("Alice");
    ClapTrap b("Alex");

    std::cout << "\n===== COPY CONSTRUCTOR =====" << std::endl;
    ClapTrap c(a);

    std::cout << "\n===== COPY ASSIGNMENT =====" << std::endl;
    c = b;

    std::cout << "\n===== BASIC ATTACK / DAMAGE / REPAIR =====" << std::endl;
    a.attack("Alex");
    b.takeDamage(3);
    b.beRepaired(2);

    std::cout << "\n===== ENERGY DEPLETION TEST =====" << std::endl;
    for (int i = 0; i < 5; ++i)
        b.attack("Cannon Fodder");

    std::cout << "\n===== DEATH TEST (HP REACHING 0) =====" << std::endl;
    ClapTrap d("Doomed");
    d.takeDamage(5);
    d.takeDamage(5);
    d.attack("Someone");
    d.beRepaired(3);

    std::cout << "\n===== END OF MAIN =====" << std::endl;
    return 0;
}
