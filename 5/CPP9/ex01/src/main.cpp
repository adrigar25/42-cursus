#include "RPN.hpp"
#include <iostream>
#include <string>



int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Usage: ./RPN <Reverse Polish Notation>" << std::endl;
        return (1);
    }

    RPN rpn;
    std::string input = argv[1];
    for(std::string::iterator it = input.begin(); it != input.end(); it++)
    {
        if(*it == ' ')
            continue;
        if(std::isdigit(*it))
            rpn.pushNumber(*it - '0');
        else
        {
            if(rpn.compute(*it) == 0)
            {
                std::cout << "Error" << std::endl;
                return (1);
            }
        }
    }
    std::cout << rpn.top() << std::endl;
    
}
