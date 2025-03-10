#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./ex01 \"<expression>\"" << std::endl;
        return 1;
    }
    try{
        long long result = RPN::calculate(argv[1]);
        std::cout << result << std::endl;
    } catch (RPN::InvalidExpression &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}