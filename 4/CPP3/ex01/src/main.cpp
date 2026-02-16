/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:56:56 by agarcia           #+#    #+#             */
/*   Updated: 2026/02/11 19:07:09 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main()
{
    ClapTrap clap("CL4P-TP");
    ScavTrap scav("SC4V-TP");

    clap.attack("Target1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    scav.attack("Target2");
    scav.takeDamage(10);
    scav.beRepaired(5);
    scav.guardGate();

    ScavTrap scav2 = scav;
    scav2.attack("Target3");

    ScavTrap scav3;
    scav3 = scav;
    scav3.guardGate();

    return 0;
}
