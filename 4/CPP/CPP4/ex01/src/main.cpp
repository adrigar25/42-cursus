/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:45:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/28 11:19:48 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"

int main() {
  std::cout << "=== Test 1: Basic array of Animals ===" << std::endl;
  const Animal *animals[4] = {new Dog(), new Cat(), new Dog(), new Cat()};

  for (int i = 0; i < 4; ++i) {
    delete animals[i];
  }

  std::cout << "\n=== Test 2: Deep Copy Test ===" << std::endl;
  
  // Create original dog
  Dog original;
  original.getBrain()->setIdea(0, "Original idea 1");
  original.getBrain()->setIdea(1, "Original idea 2");
  
  std::cout << "\nOriginal Dog ideas:" << std::endl;
  std::cout << "  " << original.getBrain()->getIdea(0) << std::endl;
  std::cout << "  " << original.getBrain()->getIdea(1) << std::endl;
  
  std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
  Dog copy1(original);
  
  std::cout << "Copy1 Dog ideas (should be same):" << std::endl;
  std::cout << "  " << copy1.getBrain()->getIdea(0) << std::endl;
  std::cout << "  " << copy1.getBrain()->getIdea(1) << std::endl;
  
  // Modify original - copy should NOT change (deep copy test)
  std::cout << "\nModifying original..." << std::endl;
  original.getBrain()->setIdea(0, "Modified idea 1");
  
  std::cout << "Original after modification:" << std::endl;
  std::cout << "  " << original.getBrain()->getIdea(0) << std::endl;
  
  std::cout << "Copy1 after original modification (should be unchanged):" << std::endl;
  std::cout << "  " << copy1.getBrain()->getIdea(0) << std::endl;
  
  // Test assignment operator
  std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
  Dog copy2;
  copy2 = original;
  
  std::cout << "Copy2 after assignment:" << std::endl;
  std::cout << "  " << copy2.getBrain()->getIdea(0) << std::endl;
  
  // Modify original again
  original.getBrain()->setIdea(0, "Modified again");
  
  std::cout << "\nOriginal after second modification:" << std::endl;
  std::cout << "  " << original.getBrain()->getIdea(0) << std::endl;
  
  std::cout << "Copy2 (should still have first modified value):" << std::endl;
  std::cout << "  " << copy2.getBrain()->getIdea(0) << std::endl;
  
  std::cout << "\n=== Deep copy test passed if copies are independent! ===" << std::endl;
  
  return 0;
}
