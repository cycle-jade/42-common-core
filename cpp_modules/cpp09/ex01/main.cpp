#include <iostream>
#include "RPN.hpp"
 
 
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: RPN \"<expression>\"" << std::endl;
        std::cerr << "Example: RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
        return 1;
    }
 
    try
    {
        RPN rpn;
        rpn.evaluate(argv[1]);
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
 
    return 0;
}