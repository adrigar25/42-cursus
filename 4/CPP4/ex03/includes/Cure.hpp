/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 00:48:12 by agarcia           #+#    #+#             */
/*   Updated: 2026/02/16 18:34:25 by agarcia          ###   ########.fr       */
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
    Cure& operator=(const Cure &other);
    ~Cure();
    AMateria* clone() const;
    void use(ICharacter& target);
};


#endif