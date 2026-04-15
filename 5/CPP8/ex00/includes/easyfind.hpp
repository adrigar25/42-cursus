#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int n);

#include "../templates/easyfind.tpp"

#endif