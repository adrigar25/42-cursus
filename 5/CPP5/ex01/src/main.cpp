#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== Test 1: Form creation and operator<< ===" << std::endl;
    Form f1("Tax Return", 50, 25);
    std::cout << f1 << std::endl;

    std::cout << "\n=== Test 2: Grade too high at Form construction ===" << std::endl;
    try
    {
        Form bad("Bad", 0, 10);
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Grade too low at Form construction ===" << std::endl;
    try
    {
        Form bad("Bad", 10, 151);
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Bureaucrat too low grade can't sign ===" << std::endl;
    Bureaucrat b1("LowGrade", 149);
    b1.signForm(f1);
    std::cout << f1 << std::endl;

    std::cout << "\n=== Test 5: Bureaucrat with enough grade signs ===" << std::endl;
    Bureaucrat b2("HighGrade", 10);
    b2.signForm(f1);
    std::cout << f1 << std::endl;

    std::cout << "\n=== Test 6: Already signed form ===" << std::endl;
    b2.signForm(f1);

    std::cout << "\n=== Test 7: Bureaucrat with exact required grade signs ===" << std::endl;
    Form f2("License", 75, 50);
    Bureaucrat b3("Exact", 75);
    b3.signForm(f2);
    std::cout << f2 << std::endl;

    return 0;
}
