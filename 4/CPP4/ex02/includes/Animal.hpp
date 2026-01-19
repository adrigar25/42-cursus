/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:27:57 by agarcia           #+#    #+#             */
/*   Updated: 2026/01/16 17:22:53 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Brain;
#include "Brain.hpp"

class Animal
{
protected:
   std::string type;
public:
   Animal();
   Animal(const Animal &other);
   virtual ~Animal();
   std::string getType() const;
   virtual void makeSound() const = 0;
   Animal& operator=(const Animal &other);
};


#endif