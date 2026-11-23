#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cerrno>
#include <iomanip>

static bool isChar(std::string const& s)
{
    return (s.length() == 1  
            && std::isprint(static_cast<unsigned char>(s[0]))
            && !std::isdigit(static_cast<unsigned char>(s[0])));
}

static bool isPseudo(std::string const& s)
{
    return (s == "nan"  || s == "nanf"  ||
            s == "+inf" || s == "+inff" ||
            s == "-inf" || s == "-inff" ||
            s == "inf"  || s == "inff");
}

static bool isInt(std::string const& s)
{
    if (s.empty())
        return false;
    size_t start = 0;
    if (s[0] == '-' || s[0] == '+')
        start = 1;
    if(start == s.length())
        return false;
    while(start < s.length())
    {
        if(!std::isdigit(static_cast<unsigned char>(s[start])))
            return false;
        start++;
    }
    return true;
}

static bool isFloat(std::string const& s)
{
    if(s.empty() || s[s.length() - 1] != 'f')
        return false;
    std::string withoutF = s.substr(0, s.length() - 1);
    if(withoutF.empty())
        return false;
    char* endPtr;
    std::strtof(withoutF.c_str(),  &endPtr);
    return (*endPtr == '\0');
}


static bool isDouble(std::string const& s)
{
    if(s.empty())
        return false;
    char* end;
    std::strtod(s.c_str(),  &end);
    return (*end == '\0');
}


//printers

static void printChar(double val , bool isPseudo)
{
    if(isPseudo || std::isnan(val)  || std::isinf(val)
         || val < 0.0 || val > 127.0)
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(val);
    if(!std::isprint(static_cast<unsigned char>(c)))
    {
        std::cout << "char: Non displayable" << std::endl;
        return;
    }else
    {
        std::cout << "char: '" << c << "'" << std::endl;
    }


}

static void printInt(double val, bool isPseudoLit)
{
    if (isPseudoLit || std::isnan(val) || std::isinf(val)
        || val < static_cast<double>(INT_MIN)
        || val > static_cast<double>(INT_MAX))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    std::cout << "int: " << static_cast<int>(val) << std::endl;
}

 
static void printFloat(double val, bool isPseudoLit)
{
    //Float supports this types
    if (isPseudoLit || std::isnan(val) || std::isinf(val))
    {
        float f = static_cast<float>(val);
        if (std::isnan(f))
            std::cout << "float: nanf" << std::endl;
        else if (f > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
        return;
    }
    float f = static_cast<float>(val);
    //fixed and precision are necessary to print the number correctly
    std::cout << std::fixed << std::setprecision(1)
              << "float: " << f << "f" << std::endl;
}
 
static void printDouble(double val, bool isPseudoLit)
{

    if (isPseudoLit || std::isnan(val) || std::isinf(val))
    {
        if (std::isnan(val))
            std::cout << "double: nan" << std::endl;
        else if (val > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
        return;
    }
    std::cout << std::fixed << std::setprecision(1)
              << "double: " << val << std::endl;
}

//The converter

void ScalarConverter::convert(std::string const& literal)
{
    bool pseudo = isPseudo(literal);
    bool charLit   = isChar(literal);
    bool intLit    = isInt(literal);
    bool floatLit  = isFloat(literal);
    bool doubleLit = isDouble(literal);

    if(!pseudo && !charLit && !intLit && !floatLit && !doubleLit)
    {
        std::cerr << "Error: Unrecognized literal" << std::endl;
        return;
    }
    double value = 0.0;
    if (charLit)
        value = static_cast<double>(literal[0]);
    else if (pseudo)
    {
         if (literal == "nan" || literal == "nanf")
            value = std::strtod("nan", NULL);
        else if (literal == "-inf" || literal == "-inff")
            value = -std::strtod("inf", NULL);
        else  // "+inf", "+inff", "inf", "inff" cause some platforms don't support the +inf literal
            value = std::strtod("inf", NULL);
    } else
    {
        std::string toParse = literal;
        if (!toParse.empty() && toParse[toParse.length() - 1] == 'f')
            toParse = toParse.substr(0, toParse.length() - 1);
 
        errno = 0;
        char* end;
        value = std::strtod(toParse.c_str(), &end);
 
        if (*end != '\0')
        {
            std::cerr << "Error: could not parse '" << literal << "'" << std::endl;
            return;
        }
    }
    printChar(value, pseudo);
    printInt(value, pseudo);
    printFloat(value, pseudo);
    printDouble(value, pseudo);
}