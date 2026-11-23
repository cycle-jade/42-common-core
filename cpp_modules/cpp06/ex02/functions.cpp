#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base *generate(void)
{
    static bool seeded = false;
    if(!seeded)
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        seeded = true;
    }

    int random =  std::rand() % 3;
    if(random == 0)
    {
        std::cout << "[generate] Created an A" << std::endl;
        return new A();
    }
    else if(random == 1)
    {
        std::cout << "[generate] Created a B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "[generate] Created a C" << std::endl;
        return new C();
    }
}


//Pointer identify version

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "It's an A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "It's a B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "It's a C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}


void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "It's an A" << std::endl;
        return;
    }
    catch (std::exception&) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "It's a B" << std::endl;
        return;
    }
    catch (std::exception&) {}
    try
    {        
        (void)dynamic_cast<C&>(p);
        std::cout << "It's a C" << std::endl;
        return;
    }
    catch (std::exception&) {}
    std::cout << "Unknown type" << std::endl;
}
