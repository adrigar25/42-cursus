/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:45:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/01 17:32:32 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"

int main()
{
  std::cout << "=== Test 1: Subject test ===" << std::endl;
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Character("me");
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete bob;
  delete me;
  delete src;
  
  std::cout << "\n=== Test 2: Full inventory (4 slots) ===" << std::endl;
  IMateriaSource* src2 = new MateriaSource();
  src2->learnMateria(new Ice());
  src2->learnMateria(new Cure());
  
  ICharacter* alice = new Character("Alice");
  tmp = src2->createMateria("ice");
  alice->equip(tmp);
  tmp = src2->createMateria("cure");
  alice->equip(tmp);
  tmp = src2->createMateria("ice");
  alice->equip(tmp);
  tmp = src2->createMateria("cure");
  alice->equip(tmp);
  
  // Try to equip 5th (should do nothing)
  tmp = src2->createMateria("ice");
  alice->equip(tmp);
  delete tmp; // Clean up since it wasn't equipped
  
  ICharacter* charlie = new Character("Charlie");
  alice->use(0, *charlie);
  alice->use(1, *charlie);
  alice->use(2, *charlie);
  alice->use(3, *charlie);
  
  delete charlie;
  delete alice;
  delete src2;
  
  std::cout << "\n=== Test 3: Unequip and use ===" << std::endl;
  IMateriaSource* src3 = new MateriaSource();
  src3->learnMateria(new Ice());
  src3->learnMateria(new Cure());
  
  ICharacter* david = new Character("David");
  AMateria* floor[10]; // To store unequipped materias
  int floorCount = 0;
  
  AMateria* ice_materia = src3->createMateria("ice");
  david->equip(ice_materia);
  tmp = src3->createMateria("cure");
  david->equip(tmp);
  
  ICharacter* eve = new Character("Eve");
  david->use(0, *eve);
  david->use(1, *eve);
  
  // Unequip slot 0 and save to floor
  floor[floorCount++] = ice_materia;
  david->unequip(0);
  
  // Try to use unequipped slot (should do nothing)
  david->use(0, *eve);
  
  // Use slot 1 (still equipped)
  david->use(1, *eve);
  
  // Clean up floor
  for (int i = 0; i < floorCount; i++)
    delete floor[i];
  
  delete eve;
  delete david;
  delete src3;
  
  std::cout << "\n=== Test 4: Unknown materia type ===" << std::endl;
  IMateriaSource* src4 = new MateriaSource();
  src4->learnMateria(new Ice());
  
  ICharacter* frank = new Character("Frank");
  tmp = src4->createMateria("fire"); // Unknown type
  if (!tmp)
    std::cout << "Cannot create unknown materia type 'fire'" << std::endl;
  
  tmp = src4->createMateria("ice");
  frank->equip(tmp);
  
  ICharacter* grace = new Character("Grace");
  frank->use(0, *grace);
  
  delete grace;
  delete frank;
  delete src4;
  
  std::cout << "\n=== Test 5: Deep copy of Character ===" << std::endl;
  IMateriaSource* src5 = new MateriaSource();
  src5->learnMateria(new Ice());
  src5->learnMateria(new Cure());
  
  ICharacter* original = new Character("Original");
  tmp = src5->createMateria("ice");
  original->equip(tmp);
  tmp = src5->createMateria("cure");
  original->equip(tmp);
  
  // Copy constructor
  Character copy1(*(Character*)original);
  
  // Assignment operator
  Character copy2("Copy2");
  copy2 = *(Character*)original;
  
  ICharacter* target = new Character("Target");
  
  std::cout << "Original uses materias:" << std::endl;
  original->use(0, *target);
  original->use(1, *target);
  
  std::cout << "Copy1 uses materias:" << std::endl;
  copy1.use(0, *target);
  copy1.use(1, *target);
  
  std::cout << "Copy2 uses materias:" << std::endl;
  copy2.use(0, *target);
  copy2.use(1, *target);
  
  delete target;
  delete original;
  delete src5;
  
  std::cout << "\n=== Test 6: Learn more than 4 materias ===" << std::endl;
  IMateriaSource* src6 = new MateriaSource();
  src6->learnMateria(new Ice());
  src6->learnMateria(new Cure());
  src6->learnMateria(new Ice());
  src6->learnMateria(new Cure());
  src6->learnMateria(new Ice()); // 5th - should do nothing
  
  ICharacter* harry = new Character("Harry");
  tmp = src6->createMateria("ice");
  harry->equip(tmp);
  
  ICharacter* iris = new Character("Iris");
  harry->use(0, *iris);
  
  delete iris;
  delete harry;
  delete src6;
  
  std::cout << "\n=== All tests completed ===" << std::endl;
  return 0;
}
