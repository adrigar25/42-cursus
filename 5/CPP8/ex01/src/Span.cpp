#include "Span.hpp"
#include <algorithm>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _values(other._values) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _values = other._values;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (_values.size() >= _maxSize)
        throw SpanFullException();
    _values.push_back(n);
}

int Span::shortestSpan()
{
    if (_values.size() < 2)
        throw NoSpanFoundException();

    std::vector<int> sorted(_values);
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i + 1 < sorted.size(); i++)
    {
        int span = sorted[i + 1] - sorted[i];
        if (span < minSpan)
            minSpan = span;
    }
    return (minSpan);
}

int Span::longestSpan()
{
    if (_values.size() < 2)
        throw NoSpanFoundException();

    int maxVal = *std::max_element(_values.begin(), _values.end());
    int minVal = *std::min_element(_values.begin(), _values.end());
    return (maxVal - minVal);
}