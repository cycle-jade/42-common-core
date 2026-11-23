#include "Zombie.hpp"

int main() {

    int i = 0;
    Zombie* heapZ =  zombieHorde(5, "Heapster");

    while (i < 5) 
    {
        heapZ[i].announce();
        i++;
    }
    
    delete[] heapZ;
    return 0;
}
