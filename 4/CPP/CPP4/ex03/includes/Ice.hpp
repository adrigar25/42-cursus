/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 00:48:12 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/30 01:28:42 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"


class Ice: public AMateria
{
public:
    Ice();
    Ice(const Ice &other);
    ~Ice();
    AMateria* clone() const;
    void use(ICharacter& target);
};


#endif