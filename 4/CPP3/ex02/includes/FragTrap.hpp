/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:02:24 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/26 11:21:29 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FROGTRAP_H
#define FROGTRAP_H

#include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
public:
    FragTrap(std::string name);
    ~FragTrap();
    void attack(const std::string& target);
    void highFivesGuys();
};

#endif