#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute):
_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){};

AForm::AForm(const AForm& other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}

AForm& AForm::operator=(const AForm& other)
{
    if(this != &other)
    {
        this->_signed = other._signed;
    }
    return (*this);
}

AForm::~AForm(){};

const std::string& AForm::getName() const
{
    return (_name);
}

int AForm::getGradeToSign() const
{
    return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (_gradeToExecute);
}

bool AForm::getSigned() const
{
    return (_signed);
}


const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is to high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is to low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() >= this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_signed = true;
}