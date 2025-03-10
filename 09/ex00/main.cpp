#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "usage: ./btc [filename]" << std::endl;
        return 1;
    }
    BitcoinExchange exchange;
    if (!exchange.loadFromFile("data.csv"))
    {
        std::cerr << "Error: could not load file" << std::endl;
        return 1;
    }
    exchange.processInputFile(av[1]);
    return 0;
}