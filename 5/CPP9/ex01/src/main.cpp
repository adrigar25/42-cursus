#include "RPN.hpp"
#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    RPN rpn;
    std::string input = argv[1];
    for (std::string::iterator it = input.begin(); it != input.end(); ++it)
    {
        if (*it == ' ')
            continue;
        if (std::isdigit(static_cast<unsigned char>(*it)))
            rpn.pushNumber(*it - '0');
        else
        {
            if (rpn.compute(*it) == 0)
            {
                std::cerr << "Error" << std::endl;
                return 1;
            }
        }
    }

    if (rpn.size() != 1 || rpn.empty())
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::cout << rpn.top() << std::endl;
    return 0;
}
