/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:52:31 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/10 14:52:31 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



int main(void)
{
    Zombie *zombie1 = new Zombie("Zombie1");
    zombie1->announce();
    delete zombie1;
    Zombie *zombie3 = newZombie("Zombie2");
    zombie3->announce();
    delete zombie3;
    randomChump("Zombie3");
    return (0);
}