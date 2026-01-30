#include "../includes/ScalarConverter.hpp"

int main(void)
{
    ScalarConverter::convert("-42");
    ScalarConverter::convert("+42");
    ScalarConverter::convert("42");
    ScalarConverter::convert("-42.2");
    ScalarConverter::convert("+42.2");
    ScalarConverter::convert("42.2");
    ScalarConverter::convert("-42.2f");
    ScalarConverter::convert("+42.2f");
    ScalarConverter::convert("42.2f");
    ScalarConverter::convert("nan");
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("inf");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("inff");
    ScalarConverter::convert("+inff");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("c");
    return (0);
}