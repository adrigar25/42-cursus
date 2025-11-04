
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook book;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\n";
			break ;
		}

		if (command == "ADD")
		{
			book.add();
		}
		else if (command == "SEARCH")
		{
			book.search();
		}
		else if (command == "EXIT")
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