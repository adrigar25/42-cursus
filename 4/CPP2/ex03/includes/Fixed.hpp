/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 23:21:38 by agarcia           #+#    #+#             */
/*   Updated: 2026/01/22 15:54:07 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
    int                _fixedPointValue;
    static const int    _fractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed (const int nbr);
    Fixed (const float nbr);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(const int raw);
    float toFloat( void ) const;
    int toInt( void ) const;
    Fixed& operator=(const Fixed& other);
    bool operator<(const Fixed& other) const;
    bool operator>(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
   friend std::ostream& operator<<(std::ostream& os, const Fixed& f);
   static Fixed& min(Fixed& fixed1, Fixed& fixed2);
   static Fixed& max(Fixed& fixed1, Fixed& fixed2);
   static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
   static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
};

#endif