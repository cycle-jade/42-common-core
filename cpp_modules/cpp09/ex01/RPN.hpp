#pragma once

# include <stack>
# include <string>

class RPN
{
    private:
    std::stack<int> _stack;
    public: 
    RPN();
    RPN(RPN const& other);
    RPN& operator=(RPN const& other);
    ~RPN();

    void evaluate(std::string const& expression);

    private:
    void applyOperator(char op);
};