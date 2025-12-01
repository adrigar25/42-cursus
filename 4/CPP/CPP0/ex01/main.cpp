/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:52:56 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/10 14:52:56 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook book;
	std::string command;

	while (true)
	{
		std::cout << "Options:" << std::endl;
		std::cout << "1. ADD\n2. SEARCH\n3. EXIT\n" << std::endl;
		std::cout << "Enter command:" << std::endl;
		if (!std::getline(std::cin, command))
		{
			std::cout << "\n";
			break ;
		}

		if (command == "1")
		{
			book.add();
		}
		else if (command == "2")
		{
			book.search();
		}
		else if (command == "3")
		{
			break ;
		}
		else
		{
			std::cout << "Unknown command. Please try again.\n";
		}
	}

	return (0);
}