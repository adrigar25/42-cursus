/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:52:01 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/10 16:31:32 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>


class Weapon
{
private:
   std::string type;
public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();
    std::string getType();
    void setType(std::string type);
};

#endif
