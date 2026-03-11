/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2026/02/16 18:14:43 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
  for (int i = 0; i < 100; ++i) {
    this->ideas[i] = "empty";
  }
  std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
  for (int i = 0; i < 100; ++i) {
    this->ideas[i] = other.ideas[i];
  }
  std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &other) {
  if (this != &other) {
    for (int i = 0; i < 100; ++i) {
      this->ideas[i] = other.ideas[i];
    }
  }
  return *this;
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

void Brain::setIdea(int index, const std::string &idea) {
  if (index >= 0 && index < 100) {
    this->ideas[index] = idea;
  }
}

std::string Brain::getIdea(int index) const {
  if (index >= 0 && index < 100) {
    return this->ideas[index];
  }
  return "";
}