/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:44:26 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/27 23:02:50 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain {
private:
  std::string ideas[100];

public:
  Brain();
  Brain(const Brain &other);
  ~Brain();
  void setIdea(int index, const std::string &idea);
  std::string getIdea(int index) const;
  Brain& operator=(const Brain &other); 
};

#endif