#include <iostream>
#include <string>
#include "iter.hpp"


template <typename T>
void print(T const& x)
{
    std::cout << x << std::endl;
}

void setTo42(int& x)
{
    x = 42;
}

void addExclaim(std::string& s)
{
    s += "!";
}

int main()
{
    std::cout << "=== 42 tests  ===" << std::endl;
 
    int tab[] = {0, 1, 2, 3, 4};
    std::size_t len = 5;
 
    iter(tab, len, print<int>);
    iter(tab, len, setTo42);
    iter(tab, len, print<int>);

    std::cout << "\n=== std::string array ===" << std::endl;
    std::string words[] = {"hello", "world", "iter"};
    iter(words, 3, print<std::string>);
 
    std::cout << "\n=== std::string after addExclaim ===" << std::endl;
    iter(words, 3, addExclaim);
    iter(words, 3, print<std::string>);
 
    std::cout << "\n=== const array (read-only) ===" << std::endl;

    int const constArr[] = {10, 20, 30};
    iter(constArr, 3, print<int>);
 
    return 0;
}