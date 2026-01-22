#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("shrubbery creation", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), _target(other._target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){};

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    std::ofstream file((this->_target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("Could not create file");
        
    std::string tree[8] = { "      /\\       ",
                            "     /**\\      ",
                            "    /****\\     ",
                            "   /******\\    ",
                            "  /********\\   ",
                            " /**********\\  ",
                            "      ||       ",
                            "      ||       "};
    
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 8; i++)
            file << tree[i] << std::endl;
        file << std::endl;
    }
    
    file.close();
}
