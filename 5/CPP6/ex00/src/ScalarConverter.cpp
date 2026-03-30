#include "../includes/ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <sstream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cctype>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

static int is_char(const std::string& literal)
{
    return (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])));
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

static bool isNan(double d)
{
    return (d != d);
}

static bool isPosInf(double d)
{
    return (d == std::numeric_limits<double>::infinity());
}

static bool isNegInf(double d)
{
    return (d == -std::numeric_limits<double>::infinity());
}

static bool isInf(double d)
{
    return (isPosInf(d) || isNegInf(d));
}

static bool parseNumberLiteral(const std::string& literal, int type, double& out)
{
    std::string toParse = literal;
    char* end = NULL;

    if (type == 2)
        toParse = literal.substr(0, literal.length() - 1);
    errno = 0;
    out = std::strtod(toParse.c_str(), &end);
    if (end == toParse.c_str() || *end != '\0')
        return (false);
    return (true);
}

static void printFloat(double d, bool parseOverflow)
{
    if (parseOverflow)
    {
        std::cout << "float: impossible\n";
        return;
    }
    if (isNan(d))
    {
        std::cout << "float: nanf\n";
        return;
    }
    if (isPosInf(d))
    {
        std::cout << "float: +inff\n";
        return;
    }
    if (isNegInf(d))
    {
        std::cout << "float: -inff\n";
        return;
    }
    if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
    {
        std::cout << "float: impossible\n";
        return;
    }

    float f = static_cast<float>(d);
    std::cout << "float: " << f;
    if (!hasDecimalOrExp(static_cast<double>(f)))
        std::cout << ".0f\n";
    else
        std::cout << "f\n";
}

static void printDouble(double d, bool parseOverflow)
{
    if (parseOverflow)
    {
        std::cout << "double: impossible\n";
        return;
    }
    if (isNan(d))
    {
        std::cout << "double: nan\n";
        return;
    }
    if (isPosInf(d))
    {
        std::cout << "double: +inf\n";
        return;
    }
    if (isNegInf(d))
    {
        std::cout << "double: -inf\n";
        return;
    }
    std::cout << "double: " << d;
    if (!hasDecimalOrExp(d))
        std::cout << ".0\n";
    else
        std::cout << "\n";
}

static void printResult(double d, bool parseOverflow)
{
    if (isNan(d) || isInf(d) || d < 0 || d > 127)
        std::cout << "char: impossible\n";
    else if (!isprint(static_cast<int>(d)))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(d) << "'\n";

    if (isNan(d) || isInf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(d) << '\n';

    printFloat(d, parseOverflow);
    printDouble(d, parseOverflow);
}

void ScalarConverter::convert(const std::string& literal)
{
    double  d = 0.0;
    bool    parseOverflow = false;
    bool    invalid = false;
    int     type = getType(literal);

    switch (type)
    {
        case -1: 
            invalid = true;
            break;
        case 0:
            d = static_cast<double>(literal[0]);
            break;
        case 1:
        case 2:
        case 3:
            if (!parseNumberLiteral(literal, type, d))
            {
                invalid = true;
                break;
            }
            parseOverflow = (errno == ERANGE);
            break;
        case 4:
            if (literal == "nan")
                d = std::numeric_limits<double>::quiet_NaN();
            else if (literal == "+inf" || literal == "inf")
                d = std::numeric_limits<double>::infinity();
            else
                d = -std::numeric_limits<double>::infinity();
            break;
        case 5:
            if (literal == "nanf")
                d = std::numeric_limits<float>::quiet_NaN();
            else if (literal == "+inff" || literal == "inff")
                d = std::numeric_limits<float>::infinity();
            else
                d = -std::numeric_limits<float>::infinity();
            break;
        default: break;
    }
    if (invalid)
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
    }
    else
        printResult(d, parseOverflow);
}
