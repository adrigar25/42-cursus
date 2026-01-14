/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:56:56 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/31 16:01:05 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clap("CL4P-TP");
    clap.attack("Target1");         
    clap.attack("Target2");         
    clap.beRepaired(3);             
    clap.takeDamage(5);             
    clap.attack("Target3");         
    clap.attack("Target4");         
    clap.attack("Target5");         
    clap.attack("Target6");         
    clap.attack("Target7");         
    clap.attack("Target8");         
    clap.attack("Target9");         
    clap.attack("Target10");        
    clap.beRepaired(5);             
    return 0;
}

// int main(void)
// {
//     ClapTrap clap("CL4P-TP");

//     clap.attack("Target1");         // Energía: 9
//     clap.attack("Target2");         // Energía: 8
//     clap.beRepaired(3);             // Energía: 7, HP: 13
//     clap.takeDamage(5);             // HP: 8
//     clap.attack("Target3");         // Energía: 6
//     clap.attack("Target4");         // Energía: 5
//     clap.attack("Target5");         // Energía: 4
//     clap.attack("Target6");         // Energía: 3
//     clap.attack("Target7");         // Energía: 2
//     clap.attack("Target8");         // Energía: 1
//     clap.attack("Target9");         // Energía: 0
//     clap.attack("Target10");        // Sin energía
//     clap.beRepaired(5);             // Sin energía

//     return 0;
// }