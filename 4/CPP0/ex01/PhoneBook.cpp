/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:53:01 by agarcia           #+#    #+#             */
/*   Updated: 2026/01/14 16:47:56 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <limits>

PhoneBook::PhoneBook(){}

PhoneBook::~PhoneBook(){}

static int	getString(std::string prompt, std::string &var)
{
	std::cout << prompt;
	std::getline(std::cin, var);
	return (!var.empty());
}

static int getNumber(std::string prompt, int &var)
{
	std::cout << prompt;
	
	if (!(std::cin >> var))
	{
    	std::cout << "\n❌ Invalid phone number\n" << std::endl;
		std::cin.clear(); 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (0);
	}

	return (1);
}

int PhoneBook::add()
{
	static int	index = 0;
	int nbr;
	std::string input;

	std::string fn;
	std::string ln;
	std::string nn;
	std::string ds;
	std::cout << "\n" << std::string(45, '-') << std::endl;
	std::cout << "          ➕ ADDING NEW CONTACT" << std::endl;
	std::cout << std::string(45, '-') << std::endl;
	while (!getString("\nEnter First name: ", fn))
		;
	while (!getString("Enter Last name: ", ln))
		;
	while (!getString("Enter Nickname: ", nn))
		;
	while (!getString("Enter Darkest Secret: ", ds))
		;
	while (!getNumber("Enter Phone Number: ", nbr))
		;
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
	std::cout << "\n✅ Contact added successfully!\n";
	index = (index + 1) % 8;
	return (0);
}
static void	printCell(const std::string &value)
{
	std::string out = value;
	if (out.length() > 10)
		out = out.substr(0, 9) + ".";
	std::cout << "|" << std::setw(10) << std::right << out;
}

static void	printContactInfo(Contact contact)
{
	std::cout << std::string(45, '-') << std::endl;
	std::cout << "  First Name      : " << contact.getFirstName() << std::endl;
	std::cout << "  Last Name       : " << contact.getLastName() << std::endl;
	std::cout << "  Nickname        : " << contact.getNickName() << std::endl;
	std::cout << "  Phone Number    : " << contact.getPhoneNumber() << std::endl;
	std::cout << "  Darkest Secret  : " << contact.getDarkestSecret() << std::endl;
	std::cout << std::string(45, '-') << std::endl;
}

int PhoneBook::search()
{
	int	index;

	if( contacts[0].getFirstName() == "")
	{
		std::cout << "\n❌ No contacts available. Please add contacts first.\n";
		return (1);
	}

	std::cout << "\n" << std::string(45, '-') << std::endl;
	std::cout << "           🔍 SEARCH CONTACTS" << std::endl;
	std::cout << std::string(45, '-') << std::endl;
	std::cout << "\n📇 Contacts:\n";
	printCell("INDEX");
	printCell("FIRST NAME");
	printCell("LAST NAME");
	printCell("NICK NAME");
	std::cout << "|\n";
	for (int i = 0; i < 8 && contacts[i].getFirstName() != ""; i++)
	{
		printCell(std::to_string(i + 1));
		printCell(contacts[i].getFirstName());
		printCell(contacts[i].getLastName());
		printCell(contacts[i].getNickName());
		std::cout << "|\n";
	}
	while (true)
	{
		std::cout << "\nEnter index to search: ";
		if(!(std::cin >> index) || index < 1 || index > 8 || contacts[index - 1].getFirstName() == "")
		{
			std::cout << "\n❌ Invalid index. Please try again." << std::endl;
			std::cin.clear(); 
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue ;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break;
	}
	
	std::cout << "\n📇 Contact Details:\n";
	printContactInfo(contacts[index - 1]);
	return (0);
}
