#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
    return (0);
}

// int main(void)
// {
//     ScalarConverter::convert("-42");
//     ScalarConverter::convert("+42");
//     ScalarConverter::convert("42");
//     ScalarConverter::convert("-42.2");
//     ScalarConverter::convert("+42.2");
//     ScalarConverter::convert("42.2");
//     ScalarConverter::convert("-42.2f");
//     ScalarConverter::convert("+42.2f");
//     ScalarConverter::convert("42.2f");
//     ScalarConverter::convert("nan");
//     ScalarConverter::convert("nanf");
//     ScalarConverter::convert("inf");
//     ScalarConverter::convert("+inf");
//     ScalarConverter::convert("-inf");
//     ScalarConverter::convert("inff");
//     ScalarConverter::convert("+inff");
//     ScalarConverter::convert("-inff");
//     ScalarConverter::convert("c");
//     return (0);
// }