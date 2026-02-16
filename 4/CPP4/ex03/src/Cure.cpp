/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 00:49:19 by agarcia           #+#    #+#             */
/*   Updated: 2026/02/16 18:48:48 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void): AMateria("cure"){};

Cure::~Cure(void){};
    
Cure::Cure(const Cure &other): AMateria(other){};

Cure& Cure::operator=(const Cure &other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return *this;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}