#include "Span.hpp"
#include <algorithm>    
#include <numeric>      
#include <stdexcept>    
#include <climits>      
 

Span::Span(unsigned int N) : _max(N)
{}
Span::Span(const Span &other) : _max(other._max), _data(other._data)
{}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _max = other._max;
        _data = other._data;
    }
    return *this;
}

Span::~Span()
{}

void Span::addNumber(int num)
{
if (_data.size() >= static_cast<std::size_t>(_max))
        throw std::length_error("Span is full: cannot add more numbers");
 
    _data.push_back(num);
}


int Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw std::logic_error("shortestSpan: need at least 2 numbers");
 
    std::vector<int> sorted(_data);
    std::sort(sorted.begin(), sorted.end());

    std::vector<int> diffs(sorted.size());
    std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());
    return *std::min_element(diffs.begin() + 1, diffs.end());
}



int Span::longestSpan() const
{
    if (_data.size() < 2)
        throw std::logic_error("longestSpan: need at least 2 numbers");

    int minVal = *std::min_element(_data.begin(), _data.end());
    int maxVal = *std::max_element(_data.begin(), _data.end());
 
    return maxVal - minVal;
}
 