/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:45:00 by agarcia           #+#    #+#             */
/*   Updated: 2026/01/07 12:03:45 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* dog = new Dog();
const Animal* cat = new Cat();
std::cout << dog->getType() << " " << std::endl;
std::cout << cat->getType() << " " << std::endl;
cat->makeSound();
dog->makeSound();   
meta->makeSound();

std::cout << "\n=== Testing Wrong Classes ===" << std::endl;
const WrongAnimal* wrongAnimal = new WrongAnimal();
const WrongAnimal* wrongCat = new WrongCat();
std::cout << wrongCat->getType() << " " << std::endl;
wrongCat->makeSound(); // Will output WrongAnimal sound!
wrongAnimal->makeSound();

delete meta;
delete dog;
delete cat;
delete wrongAnimal;
delete wrongCat;
return 0;
}
