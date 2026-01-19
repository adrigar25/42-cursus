#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;  // Forward declaration

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;


    public:
        Form(void);
        Form(const std::string name, const int gradeToSign, const int gradeToExecute);
        Form(Form& other);
        ~Form();
        void beSigned(const Bureaucrat& bureaucrat);
        const std::string& getName() const;
        int getGradeToSign();
        int getGradeToExecute();
         
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