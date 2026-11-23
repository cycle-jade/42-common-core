#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
 

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    int i = 0;
    while (i < 6)
    {
        std::cout << "\n--- Round " << i + 1 << " ---" << std::endl;
        Base* p = generate();
        std::cout << "identify(pointer): ";
        identify(p);
        std::cout << "identify(reference): ";
        identify(*p);
        delete p;
        i++;
    }
    return 0;
}