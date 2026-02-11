/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:40:32 by agarcia           #+#    #+#             */
/*   Updated: 2026/02/11 18:40:51 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
     std::cout << "ClapTrap " << this->_name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap " << this->_name << " has been copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap " << this->_name << " has been assigned!" << std::endl;
    return *this;
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
   if (amount > (unsigned int) _hitPoints)
    _hitPoints = 0;
    else
    _hitPoints -= amount;
    std::cout << "ClapTrap " << _name 
          << " takes " << amount 
          << " damage!" << std::endl;

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
    std::cout << "ClapTrap " << _name << " repairs "
              << amount << " hit points!\n";
}