/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:52:56 by agarcia           #+#    #+#             */
/*   Updated: 2026/01/14 16:33:21 by agarcia          ###   ########.fr       */
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
		std::cout << "\n" << std::string(45, '=') << std::endl;
		std::cout << "            📱 PHONEBOOK MENU 📱" << std::endl;
		std::cout << std::string(45, '=') << std::endl;
		std::cout << "  1. ADD     - Add new contact" << std::endl;
		std::cout << "  2. SEARCH  - Search contacts" << std::endl;
		std::cout << "  3. EXIT    - Exit program" << std::endl;
		std::cout << std::string(45, '=') << std::endl;
		std::cout << "\nEnter command: ";
		if (!std::getline(std::cin, command))
			break ;

		if (command == "ADD" || command == "add" || command == "1")
			book.add();
		else if (command == "SEARCH" || command == "search" || command == "2")
			book.search();
		else if (command == "EXIT" || command == "exit" || command == "3")
			break ;
		else
			std::cout << "\n❌ Unknown command. Please try again.\n";
	}

	return (0);
}