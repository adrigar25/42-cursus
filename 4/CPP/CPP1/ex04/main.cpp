/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 01:41:25 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/31 11:40:13 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>


int	main(int argc, char **argv)
{
	
	std::string filename;
	std::string s1;
	std::string s2;

	if(argc != 4)
	{
		std::cout << "Usage: ./SedIsForLosers <filename> <string 1> <string 2>" << std::endl;
		return (1);
	}

	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];


	std::ifstream file1(filename);
	std::ofstream file2(filename + ".replace", std::ios::trunc);
	std::string line;

	if(!file1.is_open())
	{
		std::cout << "Error opening file1." << std::endl;
		return (1);
	}

	if(!file2.is_open())
	{
		std::cout << "Error opening file2." << std::endl;
		return (1);
	}

	int i = 0;
	while (std::getline(file1, line))
	{
		if(line.find(s1) != std::string::npos)
		{
			i = 0;
			while(line.find(s1 , i) != std::string::npos)
			{
				file2 << line.substr(i, line.find(s1, i) - i);
				file2 << s2;
				i = line.find(s1, i) + s1.length();
			}
			file2 << line.substr(i, line.length() - i);
		}
		else
		{
		
			file2 << line;
			i += line.length();
		}
		if (!file1.eof()) 
    		file2 << std::endl;
	}
	
}
