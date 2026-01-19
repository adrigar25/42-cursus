/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:08:53 by agarcia           #+#    #+#             */
/*   Updated: 2026/01/19 15:24:15 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name): name(name){}

HumanB::~HumanB(){}

void HumanB::attack()
{
    if(this->weapon == nullptr || this->weapon->getType() == "")
        std::cout << this->name << " has no weapon to attack." << std::endl;
    else
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}


void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}