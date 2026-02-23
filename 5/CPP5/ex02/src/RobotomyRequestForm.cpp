/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:09:38 by agarcia           #+#    #+#             */
/*   Updated: 2026/02/23 19:09:38 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("robotomy request", 72, 45), _target("default"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("robotomy request", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), _target(other._target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){};

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    if(rand() % 2)
    {
        std::cout << "Brrr Brrr...\n";
        std::cout << this->_target << " has been robotomized." << std::endl;
    }
    else
        std::cout << "The robotomy failed." << std::endl;
}
