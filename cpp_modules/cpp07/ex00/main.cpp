#include <iostream>
#include <string>
#include "Whatever.hpp"


int main( void )
{
    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    std::cout << "\n--- Equal case (must return the SECOND argument) ---" << std::endl;
 
    int x = 5;
    int y = 5;

    std::cout << "min(5, 5): returns ";
    std::cout << ((&::min(x, y) == &y) ? "second (correct)" : "first (WRONG)")
              << std::endl;
    std::cout << "max(5, 5): returns ";
    std::cout << ((&::max(x, y) == &y) ? "second (correct)" : "first (WRONG)")
              << std::endl;
 
    std::cout << "\n--- float test ---" << std::endl;
    float f1 = 1.1f;
    float f2 = 2.2f;
    ::swap(f1, f2);
    std::cout << "after swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
    std::cout << "min = " << ::min(f1, f2) << std::endl;
    std::cout << "max = " << ::max(f1, f2) << std::endl;
 
    return 0;
}
