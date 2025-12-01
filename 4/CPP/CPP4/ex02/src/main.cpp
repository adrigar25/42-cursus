/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:45:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/28 16:44:09 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"

int main() {
  std::cout << "=== Test 1: Animal is abstract (cannot be instantiated) ===" << std::endl;
  
  // This should NOT compile if uncommented:
  // Animal animal;  // Error: cannot instantiate abstract class
  // Animal* ptr = new Animal();  // Error: cannot instantiate abstract class
  
  std::cout << "Animal class is abstract - cannot create Animal objects directly" << std::endl;
  
  std::cout << "\n=== Test 2: Can create Dog and Cat (concrete classes) ===" << std::endl;
  
  Dog dog;
  Cat cat;
  //Animal animal = new Animal(); // This line is just to show Animal cannot be instantiated
  
  std::cout << "\nDog type: " << dog.getType() << std::endl;
  std::cout << "Cat type: " << cat.getType() << std::endl;
  
  std::cout << "\nDog sound: ";
  dog.makeSound();
  std::cout << "Cat sound: ";
  cat.makeSound();
  
  std::cout << "\n=== Test 3: Polymorphism still works with Animal pointers ===" << std::endl;
  
  const Animal *animals[4] = {new Dog(), new Cat(), new Dog(), new Cat()};
  
  for (int i = 0; i < 4; ++i) {
    std::cout << "Animal " << i << " (" << animals[i]->getType() << ") says: ";
    animals[i]->makeSound();
  }
  
  std::cout << "\n=== Test 4: Deep copy test ===" << std::endl;
  
  Dog original;
  original.getBrain()->setIdea(0, "Original idea");
  
  Dog copy(original);
  
  std::cout << "Original idea: " << original.getBrain()->getIdea(0) << std::endl;
  std::cout << "Copy idea: " << copy.getBrain()->getIdea(0) << std::endl;
  
  original.getBrain()->setIdea(0, "Modified");
  
  std::cout << "\nAfter modifying original:" << std::endl;
  std::cout << "Original idea: " << original.getBrain()->getIdea(0) << std::endl;
  std::cout << "Copy idea (should be unchanged): " << copy.getBrain()->getIdea(0) << std::endl;
  
  std::cout << "\n=== Cleaning up ===" << std::endl;
  
  for (int i = 0; i < 4; ++i) {
    delete animals[i];
  }
  
  std::cout << "\n=== All tests passed! ===" << std::endl;
  
  return 0;
}
