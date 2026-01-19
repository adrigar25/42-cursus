#include "Bureaucrat.hpp"

int main()
{

    Bureaucrat b1("jose", 149);
    std::cout << b1 << "\n";
    b1.decrementGrade();
    std::cout << b1 << "\n";
    b1.incrementGrade();
    std::cout << b1 << std::endl;

    try
    {
        Bureaucrat b1("jose", 150);
        std::cout << b1 << std::endl;
        b1.decrementGrade();
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat b1("jose", 1);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}