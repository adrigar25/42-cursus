#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(){}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern(){}

// Funciones auxiliares para crear cada tipo de formulario
static AForm* createShrubberyForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidentialForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formType, const std::string& target)
{
    // Array de nombres de formularios
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    // Array de punteros a funciones
    AForm* (*formCreators[3])(const std::string&) = {
        &createShrubberyForm,
        &createRobotomyForm,
        &createPresidentialForm
    };
    
    // Buscar el formulario y crearlo
    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formType)
        {
            std::cout << "Intern creates " << formType << std::endl;
            return formCreators[i](target);
        }
    }
    
    std::cout << "Error: Form type \"" << formType << "\" does not exist" << std::endl;
    return NULL;
}