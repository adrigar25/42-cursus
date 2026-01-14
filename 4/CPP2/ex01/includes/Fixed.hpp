/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 23:21:38 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/26 10:36:55 by agarcia          ###   ########.fr       */
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
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int getRawBits(void) const;
    float toFloat( void ) const;
    int toInt( void ) const;
   friend std::ostream& operator<<(std::ostream& os, const Fixed& f);
};

#endif