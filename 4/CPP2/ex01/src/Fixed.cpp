/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 23:30:26 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/19 10:12:32 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
   *this = other;
};

Fixed::Fixed (const int nbr)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = nbr << _fractionalBits;
};

Fixed::Fixed(const float nbr)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(nbr * (1 << _fractionalBits));
};

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedPointValue = other._fixedPointValue;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" <<  std::endl;
    return this->_fixedPointValue;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_fixedPointValue / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->_fixedPointValue >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
    os << f.toFloat();
    return os;
}