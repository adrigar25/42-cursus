#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

class RPN
{
private:
    std::stack<int> _stack;
public:
    RPN();
    RPN(const RPN &other);
    RPN& operator=(const RPN &other);
    void pushNumber(const int num);
    int compute(const char op);
    int top() const;
    bool empty() const;
    int size() const;
    ~RPN();
};

#endif