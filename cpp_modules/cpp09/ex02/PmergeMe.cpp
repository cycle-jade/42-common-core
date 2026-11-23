#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}
 
PmergeMe::PmergeMe(PmergeMe const& other)
    : _vec(other._vec), _deq(other._deq)
{
}
 
PmergeMe& PmergeMe::operator=(PmergeMe const& other)
{
    if (this == &other)
        return *this;
 
    _vec = other._vec;
    _deq = other._deq;
    return *this;
}
 
PmergeMe::~PmergeMe()
{
}


void PmergeMe::addNumber(std::string const& token)
{
    if(token.empty())
        throw std::runtime_error("Error");

    char *end;
    long val = std::strtol(token.c_str(), &end, 10);
    if (*end != '\0')
        throw std::runtime_error("Error");
    if (val <= 0)
        throw std::runtime_error("Error");
    if(val > 2147483647L)
        throw std::runtime_error("Error");

    int n = static_cast<int>(val);
    _vec.push_back(n);
    _deq.push_back(n);
}

std::vector<int> PmergeMe::jacobsthalSequence(int n) const
{
    std::vector<int> seq;
    int a = 0;
    int b = 1;
    while (b < n)
    {
        seq.push_back(b);
        int next = b + 2 * a;
        a = b;
        b = next;
    }
    seq.push_back(n);
    return seq;
}

void PmergeMe::insertVector(std::vector<int>& main,
                    std::vector<int>& pend,
                    std::vector<int>& pairs)
{
    int             pendSize  = static_cast<int>(pend.size());
    std::vector<int> jseq     = jacobsthalSequence(pendSize);

    int prev = 0;
    for (std::size_t g = 0; g < jseq.size(); g++)
    {
        int curr = jseq[g];
        for(int idx = curr - 1; idx >= prev; idx--)
        {
            if (idx >= pendSize)
                continue;
            int valueToInsert = pend[idx];
            int pairedMain    = pairs[idx];
            std::vector<int>::iterator bound = std::lower_bound(main.begin(), main.end(), pairedMain);
            if (bound != main.end())
                ++bound;
            std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), valueToInsert);
            main.insert(pos, valueToInsert);
        }
        prev = curr;
    }
}


void PmergeMe::sortVector(std::vector<int>& seq)
{
    if(seq.size() <= 1)
        return;
    std::vector<int> main;
    std::vector<int> pend;
    std::vector<int> pairs;
    
    bool hasOdd = (seq.size() % 2 != 0);
    int Odd = hasOdd ? seq.back() : 0;

    for (std::size_t i = 0; i + 1 < seq.size() - (hasOdd ? 1 : 0); i += 2)
    {
        int a = seq[i];
        int b = seq[i + 1];
        if(a > b)
        {
            main.push_back(a);
            pend.push_back(b);
            pairs.push_back(a);
        }
        else
        {
            main.push_back(b);
            pend.push_back(a);
            pairs.push_back(b);
        }
    }
    sortVector(main);
    if(!pend.empty())
    {
       std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[0]);
        main.insert(pos, pend[0]);
    }
    if (pend.size() > 1)
    {
        std::vector<int> pendRest(pend.begin() + 1,  pend.end());
        std::vector<int> pairsRest(pairs.begin() + 1, pairs.end());
        insertVector(main, pendRest, pairsRest);
    }
    if(hasOdd)
    {
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), Odd);
        main.insert(pos, Odd);
    }
    seq = main;
}


void PmergeMe::insertDeque(std::deque<int>& main,
                            std::deque<int>& pend,
                            std::deque<int>& pairs)
{
    int              pendSize = static_cast<int>(pend.size());
    std::vector<int> jseq    = jacobsthalSequence(pendSize);
 
    int prev = 0;
 
    for (std::size_t g = 0; g < jseq.size(); g++)
    {
        int curr = jseq[g];
 
        for (int idx = curr - 1; idx >= prev; idx--)
        {
            if (idx >= pendSize)
                continue;
 
            int valueToInsert = pend[idx];
            int pairedMain    = pairs[idx];
 
            std::deque<int>::iterator bound =
                std::lower_bound(main.begin(), main.end(), pairedMain);
            if (bound != main.end())
                ++bound;
 
            std::deque<int>::iterator pos =
                std::lower_bound(main.begin(), bound, valueToInsert);
 
            main.insert(pos, valueToInsert);
        }
        prev = curr;
    }
}

void PmergeMe::sortDeque(std::deque<int>& seq)
{
    if (seq.size() <= 1)
        return;

    std::deque<int> main;
    std::deque<int> pend;
    std::deque<int> pairs;
 
    bool hasOdd = (seq.size() % 2 != 0);
    int  Odd    = hasOdd ? seq.back() : 0;
 
    for (std::size_t i = 0; i + 1 < seq.size() - (hasOdd ? 1 : 0); i += 2)
    {
        int a = seq[i];
        int b = seq[i + 1];
 
        if (a > b)
        {
            main.push_back(a);
            pend.push_back(b);
            pairs.push_back(a);
        }
        else
        {
            main.push_back(b);
            pend.push_back(a);
            pairs.push_back(b);
        }
    }
    sortDeque(main);
 
    if (!pend.empty())
    {
        std::deque<int>::iterator pos =
            std::lower_bound(main.begin(), main.end(), pend[0]);
        main.insert(pos, pend[0]);
    }
 
    if (pend.size() > 1)
    {
        std::deque<int> pendRest(pend.begin() + 1,  pend.end());
        std::deque<int> pairsRest(pairs.begin() + 1, pairs.end());
        insertDeque(main, pendRest, pairsRest);
    }
 
    if (hasOdd)
    {
        std::deque<int>::iterator pos =
            std::lower_bound(main.begin(), main.end(), Odd);
        main.insert(pos, Odd);
    }
 
    seq = main;
}
 
void PmergeMe::printSequence(std::string const& label, std::vector<int> const& seq) const
{
    std::cout << label;
    for (std::size_t i = 0; i < seq.size(); i++)
    {
        if (i > 0)
            std::cout << " ";
        std::cout << seq[i];
    }
    std::cout << std::endl;
}



void PmergeMe::sortAndTime()
{
    std::size_t n = _vec.size();
 
    printSequence("Before: ", _vec);

    struct timeval vecStart, vecEnd;
 
    gettimeofday(&vecStart, NULL);

    std::vector<int> vecWork(_vec);
    sortVector(vecWork);
 
    gettimeofday(&vecEnd, NULL);
 
    double vecTime = static_cast<double>(vecEnd.tv_sec  - vecStart.tv_sec)  * 1e6 + static_cast<double>(vecEnd.tv_usec - vecStart.tv_usec);
 
    struct timeval deqStart, deqEnd;
 
    gettimeofday(&deqStart, NULL);
 
    std::deque<int> deqWork(_deq);
    sortDeque(deqWork);
 
    gettimeofday(&deqEnd, NULL);
 
    double deqTime = static_cast<double>(deqEnd.tv_sec  - deqStart.tv_sec)  * 1e6 + static_cast<double>(deqEnd.tv_usec - deqStart.tv_usec);
 
    printSequence("After:  ", vecWork);
 
    std::cout << "Time to process a range of " << n
              << " elements with std::vector : " << vecTime << " us" << std::endl;
 
    std::cout << "Time to process a range of " << n
              << " elements with std::deque  : " << deqTime << " us" << std::endl;
}