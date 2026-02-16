/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:56:56 by agarcia           #+#    #+#             */
/*   Updated: 2026/02/11 19:06:41 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main()
{
    ClapTrap clap1;              // Default constructor
    ClapTrap clap2("CL4P-TP");   // Constructor con nombre

    clap1.attack("Target1");     // Ataque con default
    clap2.attack("Target2");
    
    clap1.takeDamage(5);         // Tomar daño
    clap2.takeDamage(12);

    clap1.beRepaired(3);         // Reparación
    clap2.beRepaired(6);

    ClapTrap clap3 = clap2;      // Copy constructor
    clap3.attack("Target3");

    clap1 = clap3;               // Assignment operator
    clap1.attack("Target4");

    return 0;
}
