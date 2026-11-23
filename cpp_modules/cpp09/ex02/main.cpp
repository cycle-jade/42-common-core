#include <iostream>
#include "PmergeMe.hpp"



int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: PmergeMe <positive integer sequence>" << std::endl;
        std::cerr << "Example: PmergeMe 3 5 9 7 4" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe pm;
        for (int i = 1; i < argc; i++)
            pm.addNumber(argv[i]);
        pm.sortAndTime();
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}