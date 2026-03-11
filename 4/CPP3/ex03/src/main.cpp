/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:56:56 by agarcia           #+#    #+#             */
/*   Updated: 2026/02/11 19:07:39 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "DiamondTrap.hpp"

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    ClapTrap clap("CL4P-TP");
    ScavTrap scav("SC4V-TP");
    FragTrap frag("FR4G-TP");
    DiamondTrap diamond("D1AM-0N");

    // Pruebas ClapTrap
    clap.attack("Target1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    // Pruebas ScavTrap
    scav.attack("Target2");
    scav.takeDamage(10);
    scav.beRepaired(5);
    scav.guardGate();

    // Pruebas FragTrap
    frag.attack("Target3");
    frag.takeDamage(15);
    frag.beRepaired(10);
    frag.highFivesGuys();

    // Pruebas DiamondTrap
    diamond.attack("Target4");
    diamond.takeDamage(20);
    diamond.beRepaired(15);
    diamond.whoAmI();

    DiamondTrap diamond2 = diamond;
    diamond2.attack("Target5");
    diamond2.whoAmI();

    DiamondTrap diamond3;
    diamond3 = diamond;
    diamond3.whoAmI();

    return 0;
}
