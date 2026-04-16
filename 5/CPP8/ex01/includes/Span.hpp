#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>
#include <stdexcept>

class Span
{
private:
    unsigned int        _maxSize;
    std::vector<int>    _values;

public:
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    void addNumber(int n);
    void addNumbers(const std::vector<int>& nums)
    {
        unsigned int count = static_cast<unsigned int>(nums.size());
        if (_values.size() + count > _maxSize)
            throw SpanFullException();
        _values.insert(_values.end(), nums.begin(), nums.end());
    }
    template <typename Iterator>
    void addRange(Iterator first, Iterator last)
    {
        unsigned int count = (unsigned int)std::distance(first, last);
        if (_values.size() + count > _maxSize)
            throw SpanFullException();
        _values.insert(_values.end(), first, last);
    }
    long long shortestSpan();
    long long longestSpan();

    class NoSpanFoundException : public std::exception
    {
        const char* what() const throw()
        {
            return "No span could be found";
        }
    };
    class SpanFullException : public std::exception
    {
        const char* what() const throw()
        {
            return "The Span is full";
        }
    };
};

#endif