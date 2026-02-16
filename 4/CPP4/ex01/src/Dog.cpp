/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:31:27 by agarcia           #+#    #+#             */
/*   Updated: 2026/02/16 18:50:13 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Dog.hpp"

Dog::Dog() {
  this->brain = new Brain();
  this->type = "Dog";
  std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
  this->brain = new Brain(*other.brain);
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other) {
  if (this != &other) {
    Animal::operator=(other);
    delete this->brain;
    this->brain = new Brain(*other.brain);
  }
  std::cout << "Dog assignment operator called" << std::endl;
  return *this;
}

Dog::~Dog() {
  delete this->brain;
  std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const { std::cout << "Woof Woof" << std::endl; }

Brain* Dog::getBrain() const { return this->brain; }
