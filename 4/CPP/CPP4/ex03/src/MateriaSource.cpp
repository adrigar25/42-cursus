/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:29:35 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/01 17:27:38 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
        this->materias[i] = NULL;
};

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
    {
        if(this->materias[i])
            delete this->materias[i];
    }
};

void MateriaSource::learnMateria(AMateria* m)
{
    if(!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (this->materias[i] == NULL)
        {
            this->materias[i] = m->clone();
            return;
        }
    }
}


AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->materias[i] && this->materias[i]->getType() == type)
        {
            return this->materias[i]->clone();
        }
    }
    return 0;
}