/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:52:11 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/10 14:53:25 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("Unnamed")
{
}

Zombie::Zombie(std::string name) : name(name)
{
}
Zombie::~Zombie()
{
    std::cout << this->name << " is being destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

void Zombie::announce(void)
{
    std::cout   << this -> name 
                << ": BraiiiiiiinnnzzzZ..." 
                << std::endl;
}