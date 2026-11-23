#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"


int main(void)
{
    std::cout << "=== Subject example ===" << std::endl;

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan()  << std::endl;


    std::cout << "\n=== Overflow test ===" << std::endl;

    try
    {
        sp.addNumber(42);
        std::cout << "ERROR: should have thrown!" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Correctly threw on full Span: " << e.what() << std::endl;
    }


    std::cout << "\n=== Too few elements ===" << std::endl;

    Span empty(10);

    try
    {
        empty.shortestSpan();
        std::cout << "ERROR: should have thrown!" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "shortestSpan on empty threw: " << e.what() << std::endl;
    }

    try
    {
        empty.longestSpan();
        std::cout << "ERROR: should have thrown!" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "longestSpan on empty threw: " << e.what() << std::endl;
    }

    empty.addNumber(42);

    try
    {
        empty.shortestSpan();
        std::cout << "ERROR: should have thrown!" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "shortestSpan on 1 element threw: " << e.what() << std::endl;
    }


    std::cout << "\n=== addRange test ===" << std::endl;

    std::vector<int> source;
    source.push_back(100);
    source.push_back(1);
    source.push_back(50);
    source.push_back(25);
    source.push_back(75);

    Span bulkSpan(5);
    bulkSpan.addRange(source.begin(), source.end());

    std::cout << "shortestSpan after addRange: " << bulkSpan.shortestSpan() << std::endl;
    std::cout << "longestSpan after addRange:  " << bulkSpan.longestSpan() << std::endl;

    try
    {
        bulkSpan.addRange(source.begin(), source.end());
        std::cout << "ERROR: should have thrown!" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Correctly threw on addRange overflow: " << e.what() << std::endl;
    }


    std::cout << "\n=== 10,000 number stress test ===" << std::endl;

    std::srand(static_cast<unsigned int>(std::time(0)));

    unsigned int const BIG = 10000;
    Span bigSpan(BIG);

    std::vector<int> bigSource;
    bigSource.reserve(BIG);

    for (unsigned int i = 0; i < BIG; i++)
        bigSource.push_back(std::rand());

    bigSpan.addRange(bigSource.begin(), bigSource.end());

    std::cout << "Stored " << BIG << " numbers" << std::endl;
    std::cout << "shortestSpan: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "longestSpan:  " << bigSpan.longestSpan()  << std::endl;

    return 0;
}
