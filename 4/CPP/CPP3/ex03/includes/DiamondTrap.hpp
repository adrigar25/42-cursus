/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:38:05 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/27 18:38:10 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap(std::string name);
        ~DiamondTrap();
        void attack(const std::string& target);
        void whoAmI();
};

#endif