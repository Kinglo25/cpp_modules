#include "RPN.hpp"

long long RPN::calculate(const char *str) {
    
    std::istringstream iss(str);
    std::stack<long long> nums;
    std::string token;
    while (iss >> token) {
        if (isOp(token)) {
            nums.push(applyOperator(nums, token));
        } 
        else if (isNum(token)) {
            nums.push(std::atoi(token.c_str()));
        } 
        else {
            throw InvalidExpression();
        }
    }
    if (nums.size() != 1)
        throw InvalidExpression();
    return nums.top();
}

bool RPN::isNum(std::string str) {
    if (str.size() != 1)
        return false;
    return std::isdigit(str[0]);
}

bool RPN::isOp(std::string str) {
    return str == "+" || str == "-" || str == "*" || str == "/";
}

long long RPN::applyOperator(std::stack<long long> &nums, std::string const &op) {
    if (nums.size() < 2)
        throw InvalidExpression();
    long long b = nums.top();
    nums.pop();
    long long a = nums.top();
    nums.pop();
    if (op == "+") {
        return add(a, b);
    } else if (op == "-") {
        return subtract(a, b);
    } else if (op == "*") {
        return multiply(a, b);
    } else if (op == "/") {
        return divide(a, b);
    }
    return 0;
}

long long RPN::add(long long a, long long b) {
    return a + b;
}

long long RPN::subtract(long long a, long long b) {
    return a - b;
}

long long RPN::multiply(long long a, long long b) {
    return a * b;
}

long long RPN::divide(long long a, long long b) {
    return a / b;
}

RPN::~RPN() {
    // destructor
}

RPN::RPN() {}

RPN::RPN ( RPN const &other ) {
  (void)other;
}

RPN &RPN::operator=( RPN const &other) {
  (void)other;
  return *this;
}