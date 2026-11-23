#include "Zombie.hpp"

int main() {

    Zombie* heapZ = newZombie("Heapster");
    heapZ->announce();
    delete heapZ;

    randomChump("Stacky");

    Zombie* z1 = newZombie("A");
    Zombie* z2 = newZombie("B");
    z1->announce();
    z2->announce();
    delete z1;
    delete z2;

    return 0;
}
