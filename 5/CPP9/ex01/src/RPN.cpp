#include "RPN.hpp"
#include <iostream>

RPN::RPN(): _stack(){};

RPN::RPN(const RPN &other): _stack(other._stack){};

RPN& RPN::operator=(const RPN &other)
{
    if(this != &other)
        _stack = other._stack;
    return (*this);
}

RPN::~RPN(){};

void RPN::pushNumber(const int num)
{
    _stack.push(num);
}

int RPN::compute(const char op)
{
    int result = 0;
    int num1;
    int num2;

    if(op != '+' && op != '*' && op != '-' && op != '/')
        return (0);

    if (_stack.size() < 2)
        return (0);

    num1 = _stack.top();
    _stack.pop();
    num2 = _stack.top();
    _stack.pop();

    if(op == '+')
        result =  num2 + num1;
    else if(op == '-')
        result = num2 - num1;
    else if(op == '*')
        result = num2 * num1;
    else if(op == '/')
        result = num2 / num1;
    _stack.push(result);
    return (1);
}

int RPN::top()
{
    if(_stack.empty())
    {
        std::cout << "Error: stack is empty" << std::endl;
        return (0);
    }
    return _stack.top();
}
