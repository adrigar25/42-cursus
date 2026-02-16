/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:31:27 by agarcia           #+#    #+#             */
/*   Updated: 2026/02/16 18:15:50 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"
#include "../includes/Cat.hpp"

Cat::Cat() {
  this->brain = new Brain();
  this->type = "Cat";
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
  this->brain = new Brain(*other.brain);
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
  if (this != &other) {
    Animal::operator=(other);
    delete this->brain;
    this->brain = new Brain(*other.brain);
  }
  std::cout << "Cat assignment operator called" << std::endl;
  return *this;
}

Cat::~Cat() {
  delete this->brain;
  std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const { std::cout << "Meow Meow" << std::endl; }

Brain* Cat::getBrain() const { return this->brain; }