#include "../includes/ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

static int is_char(const std::string& literal)
{
    return (literal.length() == 1 && !isdigit(literal[0]));
}

static int is_int(const std::string& literal)
{
    int len = static_cast<int>(literal.length());
    int i = 0;

    if(len == 0)
        return (0);
    if(literal[i] == '-' || literal[i] == '+')
        i++;
    if(i == len)
        return (0);
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
    int hasDot = 0;

    if(len < 3)
        return (0);
    if(literal[i] == '-' || literal[i] == '+')
        i++;
    for(; i < len; i++)
    {
        if(literal[i] == '.' && !hasDot)
        {
            if(i == 0 || i == len - 1)
                return (0);
            hasDot = 1;
        }
        else if(!isdigit(literal[i]))
            return (0);
    }
    return (hasDot);
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

static bool hasDecimalOrExp(double num)
{
    std::ostringstream oss;
    oss << num;
    std::string s = oss.str();
    return (s.find('.') != std::string::npos || s.find('e') != std::string::npos);
}

static void printResult(float f, double d)
{
    if (d < 0 || d > 127)
        std::cout << "char: impossible\n";
    else if (!isprint(static_cast<int>(d)))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(d) << "'\n";

    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(d) << '\n';

    std::cout << "float: " << f;
    if (!hasDecimalOrExp(static_cast<double>(f)))
        std::cout << ".0f\n";
    else
        std::cout << "f\n";

    std::cout << "double: " << d;
    if (!hasDecimalOrExp(d))
        std::cout << ".0\n";
    else
        std::cout << "\n";
}

static void printImpossible(float f, double d)
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << d << "\n\n";
}

void ScalarConverter::convert(const std::string& literal)
{
    float   f = 0.0f;
    double  d = 0.0;

    switch (getType(literal))
    {
        case -1: std::cout << "Error: Invalid literal\n"; return;
        case 0:
            d = static_cast<double>(literal[0]);
            f = static_cast<float>(literal[0]);
            break;
        case 1:
            try { d = std::stod(literal); }
            catch (std::out_of_range&) { std::cout << "Error: out of range\n"; return; }
            f = static_cast<float>(d);
            break;
        case 2:
            try { f = std::stof(literal); }
            catch (std::out_of_range&) { std::cout << "Error: out of range\n"; return; }
            d = static_cast<double>(f);
            break;
        case 3:
            try { d = std::stod(literal); }
            catch (std::out_of_range&) { std::cout << "Error: out of range\n"; return; }
            f = static_cast<float>(d);
            break;
        case 4: d = std::stod(literal); f = static_cast<float>(d); printImpossible(f, d); return;
        case 5: f = std::stof(literal); d = static_cast<double>(f); printImpossible(f, d); return;
        default: break;
    }
    printResult(f, d);
}
