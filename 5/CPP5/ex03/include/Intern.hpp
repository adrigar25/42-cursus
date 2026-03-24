#ifndef INTERN_HPP
#define INTERN_HPP

#include "../include/AForm.hpp"
#include <exception>

    class Intern
    {
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        class FormNotFoundException : public std::exception
        {
        public:
            virtual const char* what() const throw();
        };
        
        AForm* makeForm(const std::string& formName, const std::string& target);
    };

#endif