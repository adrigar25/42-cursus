/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:08:56 by agarcia           #+#    #+#             */
/*   Updated: 2026/02/23 19:08:57 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{

    Bureaucrat b1("jose", 149);
    Bureaucrat b2("pepe", 10);
    Form form("formulario 1", 50, 55);

    b1.signForm(form);
    b2.signForm(form);
}