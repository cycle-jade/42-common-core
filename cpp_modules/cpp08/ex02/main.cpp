#include <iostream>
#include <list>
#include "MutantStack.hpp"


int main(void)
{


    std::cout << "=== MutantStack ===" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl; 

    mstack.pop();                            

    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);


    MutantStack<int>::iterator it  = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;   
    --it;   
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }


    std::stack<int> s(mstack);

    std::cout << "\n=== std::list (same output expected) ===" << std::endl;

    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);

    std::cout << lst.back() << std::endl;

    lst.pop_back();                          

    std::cout << lst.size() << std::endl;   

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit  = lst.begin();
    std::list<int>::iterator lite = lst.end();

    ++lit;
    --lit;

    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }


    std::cout << "\n=== Extra tests ===" << std::endl;

    MutantStack<int> original;
    original.push(10);
    original.push(20);
    original.push(30);

    MutantStack<int> copy(original);
    copy.push(99);  

    std::cout << "original size: " << original.size() << " (expected 3)" << std::endl;
    std::cout << "copy size:     " << copy.size()     << " (expected 4)" << std::endl;


    MutantStack<int> assigned;
    assigned = original;
    assigned.push(42);

    std::cout << "original size after assign+push: " << original.size()
              << " (expected 3)" << std::endl;
    std::cout << "assigned size:                   " << assigned.size()
              << " (expected 4)" << std::endl;

    MutantStack<int> const constStack(original);

    std::cout << "const iteration: ";
    MutantStack<int>::const_iterator cit  = constStack.begin();
    MutantStack<int>::const_iterator cite = constStack.end();

    while (cit != cite)
    {
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout << std::endl;

    MutantStack<int> ops;
    ops.push(1);
    ops.push(2);
    ops.push(3);

    std::cout << "top:   " << ops.top()   << " (expected 3)" << std::endl;
    std::cout << "size:  " << ops.size()  << " (expected 3)" << std::endl;
    std::cout << "empty: " << ops.empty() << " (expected 0)" << std::endl;

    ops.pop();
    std::cout << "after pop, top: " << ops.top() << " (expected 2)" << std::endl;

    return 0;
}