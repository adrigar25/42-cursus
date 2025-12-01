/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:45:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/28 16:34:07 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* dog = new Dog();
const Animal* cat = new Cat();
const WrongAnimal* wrong = new WrongAnimal();
std::cout << dog->getType() << " " << std::endl;
std::cout << cat->getType() << " " << std::endl;
cat->makeSound();
dog->makeSound();   
meta->makeSound();
wrong->makeSound();
delete meta;
delete dog;
delete cat;
delete wrong;
return 0;
}
