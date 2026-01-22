#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <iostream>

class Bureaucrat;  

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;


    public:
        AForm(void);
        AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
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
        
        class FormNotSignedException : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

#endif