#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute):
_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){};

Form::Form(Form& other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}

Form::~Form(){};

const std::string& Form::getName() const
{
    return _name;
}

int Form::getGradeToSign()
{
    return _gradeToSign;
}

int Form::getGradeToExecute()
{
    return _gradeToExecute;
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
    if(bureaucrat.getGrade() >= this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_signed = true;
}