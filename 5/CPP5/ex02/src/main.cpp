#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureaucrat b1("jose", 149);
        Bureaucrat b2("pepe", 10);
        Bureaucrat b3("paco", 5);
        ShrubberyCreationForm shrubberyForm("home");
        RobotomyRequestForm robotomyForm("adrian");
        PresidentialPardonForm presidentialForm("adrian");

        
        b2.executeForm(shrubberyForm);

        b1.signForm(shrubberyForm);
        b2.signForm(shrubberyForm);
        b2.executeForm(shrubberyForm);



        b2.executeForm(robotomyForm);

        b1.signForm(robotomyForm);
        b2.signForm(robotomyForm);
        b2.executeForm(robotomyForm);
        b2.executeForm(robotomyForm);
        b2.executeForm(robotomyForm);
        b2.executeForm(robotomyForm);
        b2.executeForm(robotomyForm);
        b2.executeForm(robotomyForm);


        b2.executeForm(presidentialForm);

        b1.signForm(presidentialForm);
        b2.signForm(presidentialForm);
        b2.executeForm(presidentialForm);
        b3.executeForm(presidentialForm);
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}