#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"


int main(void)
{


    std::cout << "=== std::vector<int> ===" << std::endl;

    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(7);
    vec.push_back(42);
    vec.push_back(9);
    vec.push_back(15);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Found 42 at index "
                  << std::distance(vec.begin(), it) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected throw: " << e.what() << std::endl;
    }

    try
    {
        easyfind(vec, 99);
        std::cout << "ERROR: should have thrown!" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Correctly threw for 99: " << e.what() << std::endl;
    }


    std::cout << "\n=== std::list<int> ===" << std::endl;

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 30);
        std::cout << "Found 30 at position "
                  << std::distance(lst.begin(), it) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected throw: " << e.what() << std::endl;
    }

    try
    {
        easyfind(lst, 5);
        std::cout << "ERROR: should have thrown!" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Correctly threw for 5: " << e.what() << std::endl;
    }


    std::cout << "\n=== std::deque<int> ===" << std::endl;

    std::deque<int> dq;
    dq.push_back(100);
    dq.push_back(200);
    dq.push_back(300);

    try
    {
        std::deque<int>::iterator it = easyfind(dq, 100);
        std::cout << "Found 100 at index "
                  << std::distance(dq.begin(), it) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected throw: " << e.what() << std::endl;
    }

    try
    {
        easyfind(dq, 999);
        std::cout << "ERROR: should have thrown!" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Correctly threw for 999: " << e.what() << std::endl;
    }

    std::cout << "\n=== const std::vector<int> ===" << std::endl;

    std::vector<int> const constVec(vec); 

    try
    {
        std::vector<int>::const_iterator it = easyfind(constVec, 7);
        std::cout << "Found 7 at index "
                  << std::distance(constVec.begin(), it) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected throw: " << e.what() << std::endl;
    }

    try
    {
        easyfind(constVec, 0);
        std::cout << "ERROR: should have thrown!" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Correctly threw for 0: " << e.what() << std::endl;
    }

    return 0;
}