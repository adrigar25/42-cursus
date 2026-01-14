/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:18:40 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/01 17:17:23 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "./iMateriaSource.hpp"
#include "./AMateria.hpp"

class MateriaSource: public IMateriaSource
{
    private:
        AMateria* materias[4];
    public:
     MateriaSource();
     ~MateriaSource();
     void learnMateria(AMateria*);
     AMateria* createMateria(std::string const & type);
};

#endif
