/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 01:41:25 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/10 14:48:33 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPtr = &str;
	std::string &strRef = str;

	std::cout << "ADDRESSES:" << std::endl;

	std::cout << "str:" << &str << std::endl;
	std::cout << "strPtr:" << strPtr << std::endl;
	std::cout << "strRef:" << &strRef << std::endl;

	std::cout << "VALUES:" << std::endl;

	std::cout << "str:" << str << std::endl;
	std::cout << "strPtr:" << *strPtr << std::endl;
	std::cout << "strRef:" << strRef << std::endl;
}
