#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other){
    this->_stack = other._stack;
}

RPN& RPN::operator=(const RPN& other) {
    if(this != &other)
        this->_stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const {
    return (c == '+'|| c == '-' || c == '*' || c == '/');
}

void RPN::performOperation(char op) {
    if(_stack.size() < 2) {
        std::cerr << "Error" << std::endl;
        exit(1);
    }

    int b = _stack.top(); _stack.pop();
    int a = _stack.top(); _stack.pop();
    int result = 0;

    switch(op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': 
            if (b == 0) {
                std::cerr << "Error: division by 0" << std::endl;
                exit(1);
            }
            result = a / b; 
            break;
        default:
            std::cerr << "Error: Invalid Operator" << std::endl;
            exit(1);
    }
    _stack.push(result);
}

void RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while(iss >> token) {
        if(token.length() == 1 && isOperator(token[0]))
            performOperation(token[0]);
        else if(isdigit(token[0])) {
            int num = std::atoi(token.c_str());
            if(num < 0 || num > 9){
                std::cerr << "Error: Only Single Digit Numbers are allowed" << std::endl;
                exit(1);
            }
            _stack.push(num);
        }
        else {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
    }
    if (_stack.size() != 1) {
            std::cerr << "Error" << std::endl;
            exit(1);
    }
    std::cout << _stack.top() << std::endl;
}
