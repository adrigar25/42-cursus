/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 00:51:57 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/30 01:32:50 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"

AMateria::AMateria(std::string const &type): type(type){};

AMateria::AMateria(const AMateria &other): type(other.type){};

AMateria& AMateria::operator=(const AMateria &other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

AMateria::~AMateria(){};

std::string const & AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* uses " << this->type << " on " << target.getName() << " *" << std::endl;
}