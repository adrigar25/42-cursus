/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 00:27:27 by agarcia           #+#    #+#             */
/*   Updated: 2026/01/19 15:23:02 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

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
    
   
    switch (i)
    {
    case 0:
        harl.complain("DEBUG");
        harl.complain("INFO");
        harl.complain("WARNING");
        harl.complain("ERROR");
        break;
    case 1:
        harl.complain("INFO");
        harl.complain("WARNING");
        harl.complain("ERROR");
        break;
    case 2:
        harl.complain("WARNING");
        harl.complain("ERROR");
        break;
    case 3:
        harl.complain("ERROR");
        break;
    
    default:
        break;
    }
    
}