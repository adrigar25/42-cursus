/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 01:41:25 by agarcia           #+#    #+#             */
/*   Updated: 2026/01/19 15:20:25 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"
#include <iostream>
#include <string>


int	main(void)
{
	int n = 0;
	std::string name;

	std::cout << "Number of zombies:" << std::endl;
	std::cin >> n;
	if (n <= 0)
	{
		std::cout << "Invalid number of zombies (default=5)" << std::endl;
        n = 5;
    }

	std::cout << "Name of zombies:" << std::endl;
	std::cin >> name;
	Zombie *horde = zombieHorde(n, name);

	for (int i = 0; i < n; i++)
	{
		horde[i].announce();
	}

	delete[] horde;
}