/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 00:49:19 by agarcia           #+#    #+#             */
/*   Updated: 2026/02/16 18:48:54 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void): AMateria("ice"){};

Ice::~Ice(void){};

Ice::Ice(const Ice &other): AMateria(other){};

Ice& Ice::operator=(const Ice &other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return *this;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}