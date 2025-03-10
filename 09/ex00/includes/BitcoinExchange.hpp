#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>


class BitcoinExchange {
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    
    bool loadFromFile(const char *filename);
    float getRate(const std::string &currency) const;
    void processInputFile(const std::string &filename) const;
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& value) const; 

private:
    std::map <std::string, float> rates;
};

#endif // BITCOINEXCHANGE_HPP