/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 00:48:12 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/30 01:37:27 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"


class Cure: public AMateria
{
public:
    Cure();
    Cure(const Cure &other);
    ~Cure();
    AMateria* clone() const;
    void use(ICharacter& target);
};


#endif