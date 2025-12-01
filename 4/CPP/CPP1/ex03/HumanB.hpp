/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:58:57 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/10 16:51:50 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
   std::string name;
   Weapon *weapon;
public:
    HumanB(std::string name);
    ~HumanB();
    void setWeapon(Weapon &Weapon);
    void attack();
};

#endif