/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:08:51 by agarcia           #+#    #+#             */
/*   Updated: 2026/03/05 18:46:20 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;


    public:
        Form();
        Form(const std::string name, const int gradeToSign, const int gradeToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        void beSigned(const Bureaucrat& bureaucrat);
        const std::string& getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getSigned() const;
         
        class GradeTooHighException : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif