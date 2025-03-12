#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN {
private:
    std::stack<int> _stack;

    bool isOperator(char c) const;
    void performOperation(char op); // will two numbers, apply operation and pushe the result.

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    void evaluate(const std::string& expression); // this should process the input
};

#endif
