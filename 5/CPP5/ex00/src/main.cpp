#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Test 1: Normal creation and output ===" << std::endl;
    Bureaucrat b1("Alice", 1);
    Bureaucrat b2("Bob", 150);
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    std::cout << "\n=== Test 2: incrementGrade and decrementGrade ===" << std::endl;
    Bureaucrat b3("Charlie", 5);
    std::cout << b3 << std::endl;
    b3.incrementGrade();
    std::cout << "After increment: " << b3 << std::endl;
    b3.decrementGrade();
    std::cout << "After decrement: " << b3 << std::endl;

    std::cout << "\n=== Test 3: Grade too high at construction (0) ===" << std::endl;
    try
    {
        Bureaucrat bad("Bad", 0);
        std::cout << bad << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Grade too low at construction (151) ===" << std::endl;
    try
    {
        Bureaucrat bad("Bad", 151);
        std::cout << bad << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: incrementGrade on grade 1 ===" << std::endl;
    try
    {
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        top.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: decrementGrade on grade 150 ===" << std::endl;
    try
    {
        Bureaucrat bottom("Bottom", 150);
        std::cout << bottom << std::endl;
        bottom.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Copy constructor and assignment ===" << std::endl;
    Bureaucrat b4("Dave", 42);
    Bureaucrat b5(b4);
    Bureaucrat b6("Eve", 100);
    b6 = b4;
    std::cout << b4 << std::endl;
    std::cout << b5 << std::endl;
    std::cout << b6 << std::endl;

    return 0;
}
