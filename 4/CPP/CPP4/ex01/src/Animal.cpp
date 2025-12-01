/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:32:56 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/28 16:26:34 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    this->type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    this->type = other.type;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}