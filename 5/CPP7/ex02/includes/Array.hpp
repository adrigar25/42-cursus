#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stdexcept>

template <typename T>
class Array
{
private:
    T* _data;
    unsigned int _size;
public:
    Array();
    Array(unsigned int n);
    Array(Array const &other);
    Array& operator=(const Array &other);
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;
    ~Array();
    class OutOfBoundsException : public std::exception
    {
        const char* what() const throw()
        {
            return "Index out of bounds";
        }
    };
};

#include "../templates/Array.tpp"

#endif