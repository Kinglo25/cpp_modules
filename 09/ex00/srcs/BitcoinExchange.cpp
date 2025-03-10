#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <algorithm>

// Default constructor
BitcoinExchange::BitcoinExchange() {}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : rates(other.rates) {}

// Assignment operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        rates = other.rates;
    }
    return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadFromFile(const char *filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        return false;
    
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date;
        float rate;
        if (std::getline(iss, date, ',') && iss >> rate) {
            rates[date] = rate;
        }
    }
    return true;
}

void BitcoinExchange::processInputFile(const std::string& filename) const {
    std::ifstream infile(filename.c_str());
    if (!infile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(infile, line);
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string date, value_str;
        if (std::getline(iss, date, '|') && std::getline(iss, value_str)) {
            if (!isValidDate(date)) {
                std::cerr << "Error: invalid date => " << date << std::endl;
                continue;
            }
            if (!isValidValue(value_str)) {
                std::cerr << "Error: invalid value => " << value_str << std::endl;
                continue;
            }
            try {
                std::istringstream valueStream(value_str);
                float value;
                valueStream >> value;
                if (valueStream.fail()) {
                    throw std::invalid_argument("Invalid float value");
                }
                float rate = getRate(date);
                std::cout << date << " => " << value << " = " << value * rate << std::endl;
            } catch (const std::invalid_argument&) {
                std::cerr << "Error: invalid value." << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.size() != 11) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7) continue;
        if (date[i] == ' ') continue;
        if (!std::isdigit(date[i])) return false;
    }

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    // Check days in month
    if (month == 2) { // February
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28)) return false;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) { // April, June, September, November
        if (day > 30) return false;
    }

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value_str) const {
    try {
        std::istringstream valueStream(value_str);
        float value;
        valueStream >> value;
        if (valueStream.fail() || value < 0 || value > 1000) {
            return false;
        }
        return true;
    } catch (const std::invalid_argument&) {
        return false;
    }
}

float BitcoinExchange::getRate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = rates.lower_bound(date);
    if (it == rates.end() || it->first != date) {
        if (it == rates.begin()) {
            return 0.0f; // No earlier date available
        }
        --it;
    }
    return it->second;
}