/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:08:55 by agarcia           #+#    #+#             */
/*   Updated: 2026/02/23 19:08:55 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute):
_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
};

Form::Form(const Form& other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}

Form& Form::operator=(const Form& other)
{
    if(this != &other)
    {
        this->_signed = other._signed;
    }
    return (*this);
}

Form::~Form(){};

const std::string& Form::getName() const
{
    return (_name);
}

int Form::getGradeToSign() const
{
    return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (_gradeToExecute);
}

bool Form::getSigned() const
{
    return (_signed);
}


const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is to high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is to low!";
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "Form " << form.getName()
        << " | signed: " << (form.getSigned() ? "yes" : "no")
        << " | grade to sign: " << form.getGradeToSign()
        << " | grade to execute: " << form.getGradeToExecute();
    return out;
}