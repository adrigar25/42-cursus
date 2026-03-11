#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int n)
{
    typename T::iterator it = container.begin();

    while (it != container.end())
    {
        if (*it == n)
            return it;
        ++it;
    }

    throw std::runtime_error("Element not found");
}

#endif