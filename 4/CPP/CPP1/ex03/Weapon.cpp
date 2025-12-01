/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:14:27 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/10 16:31:56 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon(){}

Weapon::Weapon(std::string type): type(type){}

Weapon::~Weapon(){}

std::string Weapon::getType()
{
    return(this->type);
}

void Weapon::setType(std::string type)
{
    this->type = type;
}