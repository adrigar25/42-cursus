/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 00:27:27 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/31 11:58:27 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl = Harl();
    std::string levels[4] = {"DEBUG","INFO","WARNING","ERROR"};
    int i = 0;
    if(argc != 2)
    {
        std::cout << "Usage: ./harlFilter <levelFilter>" << std::endl;
        return (1);
    }

    while (i <= 3)
    {
        if(levels[i] == argv[1])
            break;
        i++;
    }

    if(i > 3)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return (0);
    }
    
   
    for (int j = i; j <= 3; j++)
    {
        harl.complain(levels[j]);
        std::cout << std::endl;
    }
}