/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:53:01 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/01 18:33:47 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <limits>

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook(){}

static int	getValue(std::string prompt, std::string &var)
{
	std::cout << prompt;
	std::getline(std::cin, var);
	return (!var.empty());
}

int PhoneBook::add()
{
	static int	index = 1;
	int			nbr;

	std::string fn;
	std::string ln;
	std::string nn;
	std::string ds;
	while (!getValue("Enter First name: ", fn))
		;
	while (!getValue("Enter Last name: ", ln))
		;
	while (!getValue("Enter Nickname: ", nn))
		;
	while (!getValue("Enter Darkest Secret: ", ds))
		;
	while (true)
	{
		std::cout << "Enter Phone Number: ";
		std::cin >> nbr;
		if (!nbr || nbr < std::numeric_limits<int>::min()
			|| nbr > std::numeric_limits<int>::max())
		{
			std::cout << "Invalid Phone number" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			break ;
	}
	if (contacts[index].getFirstName().empty())
		contacts[index] = Contact(fn, ln, nn, ds, nbr);
	else
	{
		contacts[index].setFirstName(fn);
		contacts[index].setLastName(ln);
		contacts[index].setNickName(nn);
		contacts[index].setDarkestSecret(ds);
		contacts[index].setPhoneNumber(nbr);
	}
	if (index < 7)
		index = (index + 1) % 8;
	return (0);
}
void	printCell(const std::string &value)
{
	std::string out = value;
	if (out.length() > 10)
		out = out.substr(0, 9) + "."; // deja 9 chars + punto
	std::cout << "|" << std::setw(10) << std::right << out;
}

void	printContactInfo(Contact contact)
{
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickName() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

int PhoneBook::search()
{
	int	index;

	std::cout << "📇 Contacts:\n";
	printCell("INDEX");
	printCell("FIRST NAME");
	printCell("LAST NAME");
	printCell("NICK NAME");
	std::cout << "|\n";
	for (int i = 1; i <= 8 && contacts[i].getFirstName() != ""; i++)
	{
		printCell(std::to_string(i));
		printCell(contacts[i].getFirstName());
		printCell(contacts[i].getLastName());
		printCell(contacts[i].getNickName());
		std::cout << "|\n";
	}
	std::cout << "\nEnter index to search: ";
	std::cin >> index;
	std::cin.ignore();
	if (index > std::numeric_limits<int>::max()
		|| index < std::numeric_limits<int>::min())
	{
		std::cout << "❌ Index out of range.\n";
		return (1);
	}
	index = static_cast<int>(index);
	std::cout << "\n📇 Contact Details:\n";
	printContactInfo(contacts[index]);
	return (0);
}
