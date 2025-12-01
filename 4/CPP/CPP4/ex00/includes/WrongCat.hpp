/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:55:40 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/26 13:58:23 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>

class WrongCat
{
protected:
    std::string type;
public:
    WrongCat();
    ~WrongCat();
    void makeSound() const;
};

#endif