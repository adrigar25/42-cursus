/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:40:32 by agarcia           #+#    #+#             */
/*   Updated: 2026/01/07 11:19:45 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
     std::cout << "ClapTrap " << this->_name << " has been created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name << " has been destroyed!" << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
    if(this->_energyPoints <= 0 || this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy points or hit points to attack." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->_energyPoints <= 0 || this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy points or hit points to repair." << std::endl;
        return;
    }
    this->_hitPoints += amount;
    this->_energyPoints--;
}