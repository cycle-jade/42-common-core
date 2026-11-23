#pragma once
# include <vector>
# include <stdexcept>
# include <algorithm>

class Span
{
    private:
        unsigned int     _max;
        std::vector<int> _data;
    public:
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        void addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;
        template <typename InputIterator>
        void addRange(InputIterator first, InputIterator last)
        {
            unsigned int incoming = static_cast<unsigned int>(std::distance(first, last));
            if (_data.size() + incoming > _max)
                throw std::length_error("addRange: not enough capacity for this range");
            _data.insert(_data.end(), first, last);
        }
};
