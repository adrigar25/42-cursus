/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:56:56 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/26 11:12:21 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap clap("CL4P-TP");
    ScavTrap scav("SC4V-TP");

    clap.attack("a target");
    clap.takeDamage(5);
    clap.beRepaired(3);
    scav.attack("another target");
    scav.takeDamage(10);
    scav.beRepaired(5);
    scav.guardGate();

    return 0;
}