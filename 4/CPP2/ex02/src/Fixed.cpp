/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 23:30:26 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/25 18:57:38 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): _fixedPointValue(0)
{
};

Fixed::Fixed(const Fixed& other)
{
   *this = other;
};

Fixed::Fixed (const int nbr)
{
    this->_fixedPointValue = nbr << _fractionalBits;
};

Fixed::Fixed(const float nbr)
{
    this->_fixedPointValue = roundf(nbr * (1 << _fractionalBits));
};

Fixed::~Fixed()
{
};

int Fixed::getRawBits(void) const
{
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

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->_fixedPointValue = other._fixedPointValue;
    return *this;
}

bool Fixed::operator>(const Fixed& other) const
{
    return (this->_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->_fixedPointValue < other._fixedPointValue);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->_fixedPointValue >= other._fixedPointValue);
}
bool Fixed::operator<=(const Fixed& other) const
{
    return (this->_fixedPointValue <= other._fixedPointValue);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->_fixedPointValue != other._fixedPointValue);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
    this->_fixedPointValue++;
    return *this;
}

Fixed& Fixed::operator--()
{
     this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_fixedPointValue++;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_fixedPointValue--;
    return temp;
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
    if(fixed1._fixedPointValue < fixed2._fixedPointValue)
        return fixed1;
    return fixed2;
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
    if(fixed1._fixedPointValue > fixed2._fixedPointValue)
        return fixed1;
    return fixed2;
}
const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
    if(fixed1._fixedPointValue < fixed2._fixedPointValue)
        return fixed1;
    return fixed2;
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
    if(fixed1._fixedPointValue > fixed2._fixedPointValue)
        return fixed1;
    return fixed2;
}