/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:58:57 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/10 16:48:20 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
   std::string name;
   Weapon  &weapon;
public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    void attack();
};


#endif