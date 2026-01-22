#include "Bureaucrat.hpp"

int main()
{

    Bureaucrat b1("jose", 149);
    Bureaucrat b2("pepe", 10);
    Form form("formulario 1", 50, 55);

    b1.signForm(form);
    b2.signForm(form);
}