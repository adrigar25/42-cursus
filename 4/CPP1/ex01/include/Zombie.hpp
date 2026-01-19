/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 01:30:02 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/10 10:05:32 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
  private:
	std::string name;

  public:
  	Zombie();
	Zombie(std::string name);
	~Zombie();
	void setName(std::string name);
	void announce(void);
};

Zombie	*zombieHorde(int N, std::string name);

#endif