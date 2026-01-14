/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:07:24 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/26 11:21:20 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " has been created!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " has been destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& tarjet)
{
    if(this->_energyPoints <=0 || this->_hitPoints <=0)
    {
        std::cout << "FragTrap " << this->_name << " has no energy points or hit points to attack." << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->_name << " attacks " << tarjet << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->_name << " is requesting a high five!" << std::endl;
}
