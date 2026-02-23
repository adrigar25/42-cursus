/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:09:36 by agarcia           #+#    #+#             */
/*   Updated: 2026/02/23 19:09:36 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("presidential pardon", 25, 5), _target("default"){}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
    : AForm("presidential pardon", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
    : AForm(other), _target(other._target){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){};

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
