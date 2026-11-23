#include "ScalarConverter.hpp"
#include <iostream>


int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        std::cerr << "Examples:" << std::endl;
        std::cerr << "  " << argv[0] << " 42" << std::endl;
        std::cerr << "  " << argv[0] << " 4.2f" << std::endl;
        std::cerr << "  " << argv[0] << " a" << std::endl;
        std::cerr << "  " << argv[0] << " nan" << std::endl;
        return 1;
    }
    //Cause member function is static, we can call it without an instance of ScalarConverter
    ScalarConverter::convert(std::string(argv[1]));
    return 0;
}