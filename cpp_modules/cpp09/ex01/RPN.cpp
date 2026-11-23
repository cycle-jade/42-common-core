#include "RPN.hpp"
 
#include <iostream>
#include <sstream>
#include <stdexcept>

RPN::RPN(){}

RPN::RPN(RPN const& other) : _stack(other._stack){}

RPN& RPN::operator=(RPN const& other)
{
    if (this == &other)
        return *this;
    _stack = other._stack;
    return *this;
}

RPN::~RPN(){}

void RPN::applyOperator(char op)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error");
    int right = _stack.top(); 
    _stack.pop();
    int left = _stack.top();
    _stack.pop();

    int result;
    switch (op)
    {
        case '+':
            result = left + right;
            break;

        case '-':
            result = left - right;
            break;

        case '*':
            result = left * right;
            break;

        case '/':
            if (right == 0)
                throw std::runtime_error("Error");
            result = left / right;
            break;

        default:
            throw std::runtime_error("Error");
    }
    _stack.push(result);
}


void RPN::evaluate(std::string const& expression)
{
    while (!_stack.empty())
        _stack.pop();
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token)
    {
        if(token.length() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
        {
            _stack.push(token[0] - '0');
        }
        else if (token.length() == 1 &&
                 (token[0] == '+' || token[0] == '-' ||
                  token[0] == '*' || token[0] == '/'))
        {
            applyOperator(token[0]);
        }
        else
        {
            throw std::runtime_error("Error: invalid token in expression");
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");
    std::cout << _stack.top() << std::endl;
}