#include "../includes/ScalarConverter.hpp"
#include <iostream>

static int is_char(const std::string& literal)
{
    return (literal.length() == 1 && !isdigit(literal[0]));
}

static int is_int(const std::string& literal)
{
    int len = static_cast<int>(literal.length());
    int i = 0;

    if(literal[i] == '-' || literal[i] == '+')
        i++;

    for(; i < len; i++)
    {
        if(!isdigit(literal[i]))
            return (0);
    }
    
    return (1);
}
 
static int is_double(const std::string& literal)
{
    int len = static_cast<int>(literal.length());
    int i = 0;

    if(len < 3)
        return (0);

    if(literal[i] == '-' || literal[i] == '+')
        i++;

    for(; i < len; i++)
    {
        if(literal[i] == '.')
        {
            if(i == 0 || i == len - 1)
                return (0);
            i++;
            break;
        }
        if(!isdigit(literal[i]))
            return (0);
    }
    return (1);
}

static int is_float(const std::string& literal)
{
    int len = static_cast<int>(literal.length());
    if(len < 4)
        return (0);
    if(literal[len - 1] != 'f') return (0);
    std::string sub = literal.substr(0, len - 1);
    return (is_double(sub));
}

static int getType(const std::string& literal)
{
    if (is_char(literal))
        return (0);
    else if (is_int(literal))
        return (1);
    else if (is_float(literal))
        return (2);
    else if (is_double(literal))
        return (3);
    else if(literal == "nan"
            || literal == "+inf" 
            || literal == "-inf" 
            || literal == "inf")
        return (4);
    else if(literal == "nanf" 
            || literal == "+inff" 
            || literal == "-inff" 
            || literal == "inff")
        return (5);
    return (-1);
}



void ScalarConverter::convert(const std::string& literal)
{
    char character = '\0';
    int integerNum = 0;
    double doubleNum = 0.0;
    float floatNum = 0.0f;


    switch (getType(literal))
    {
        case -1:
            std::cout << "Error: Invalid literal" << std::endl;
            return;
        case 0:
            character = literal[0];
            integerNum = static_cast<int>(character);
            floatNum = static_cast<float>(character);
            doubleNum = static_cast<double>(character);
            break;
        case 1:
            integerNum = std::stoi(literal);
            character = static_cast<char>(integerNum);
            floatNum = static_cast<float>(integerNum);
            doubleNum = static_cast<double>(integerNum);
            break;
        case 2:
            floatNum = std::stof(literal);
            character = static_cast<char>(floatNum);
            integerNum = static_cast<int>(floatNum);
            doubleNum = static_cast<double>(floatNum);
            break;
        case 3:
            doubleNum = std::stod(literal);
            character = static_cast<char>(doubleNum);
            integerNum = static_cast<int>(doubleNum);
            floatNum = static_cast<float>(doubleNum);
            break;
        case 4:
            doubleNum = std::stod(literal);
            floatNum = static_cast<float>(doubleNum);
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: " << floatNum << "f\n";
            std::cout << "double: " << doubleNum << "\n" << std::endl;
            return;
        case 5:
            floatNum = std::stof(literal);
            doubleNum = static_cast<double>(floatNum);
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: " << floatNum << "f\n";
            std::cout << "double: " << doubleNum << "\n" << std::endl;
            return;
        default:
            break;
    }

    std::cout << "char: ";
        if (isprint(character))
            std::cout << "'" << character << "'\n";
        else
            std::cout << "Non displayable" << '\n';

        std::cout << "int: " << integerNum << '\n';
        std::cout << "float: " << floatNum << "f" << '\n';
        std::cout << "double: " << doubleNum << '\n' << std::endl;
}