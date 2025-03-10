#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#include <string>
#include <exception>
#include <sstream>
#include <cstdlib>

class RPN {
private:
    RPN(); // default constructor
    RPN(const RPN &other); // copy constructor
    RPN &operator=(const RPN &other); // assignment operator
    
    static bool isOp(std::string str);
    static bool isNum(std::string str);
    
    static long long applyOperator(std::stack<long long> &nums, std::string const &op);
    static long long add(long long a, long long b);
    static long long subtract(long long a, long long b);
    static long long multiply(long long a, long long b);
    static long long divide(long long a, long long b);

public:  
    ~RPN(); // destructor
    static long long calculate(const char *str);

    class InvalidExpression : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Invalid expression";
        }
    };
};

#endif