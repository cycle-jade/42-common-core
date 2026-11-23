#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <cerrno> 

BitcoinExchange::BitcoinExchange()
{
    if(!loadDatabase("data.csv"))
    {
        throw std::runtime_error("Failed to load database");
    }
}


BitcoinExchange::BitcoinExchange(BitcoinExchange const& other) : _db(other._db)
{}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& other)
{
    if (this == &other)
        return *this;
 
    _db = other._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

std::string BitcoinExchange::trim(std::string const& s) const
{
    std::size_t start = s.find_first_not_of(" \t\r\n");
    if(start == std::string::npos)
        return "";
    std::size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

bool BitcoinExchange::loadDatabase(std::string const& csvPath)
{
    std::ifstream file(csvPath.c_str());

    if(!file.is_open())
        return false;

    std::string line;
    std::getline(file, line); // Skip header
    while(std::getline(file, line))
    {
        if(line.empty())
            continue;
        std::size_t commaPos = line.find(',');
        if(commaPos == std::string::npos)
            continue;
        std::string date = trim(line.substr(0, commaPos));
        std::string rateStr = trim(line.substr(commaPos + 1));
        if(date.empty() || rateStr.empty())
            continue;
        char *endPtr;
        float rate = std::strtof(rateStr.c_str(), &endPtr);
        if(*endPtr != '\0')
            continue;
        _db[date] = rate;// If date doesn't exist in the map, it's inserted.
    }
    return !_db.empty();
}



bool BitcoinExchange::isValidDate(std::string const& date) const
{
    if(date.length() != 10)
        return false;
    if(date[4] != '-' || date[7] != '-')
        return false;
    
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    int year , month, day;

    std::istringstream ys(date.substr(0, 4));
    std::istringstream ms(date.substr(5, 2));
    std::istringstream ds(date.substr(8, 2));

    ys >> year;
    ms >> month;
    ds >> day;
    if(year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(std::string const& valueStr, float& outValue) const
{
    if(valueStr.empty())
        return false;
    char *endPtr;
    errno = 0;

    outValue = std::strtof(valueStr.c_str(), &endPtr);
    if(*endPtr != '\0' || endPtr == valueStr.c_str())
        return false;//not a number at all
    
    return true;
}

void BitcoinExchange::process(std::string const& inputPath)
{
    std::ifstream file(inputPath.c_str());
    if(!file.is_open())
    {
        std::cerr << "Error: Could not open input file." << std::endl;
        return;
    }
    std::string line;
    bool isFirstLine = true;
    while(std::getline(file, line))
    {
        if(isFirstLine)
        {
            isFirstLine = false;
            continue;
        }
        if (line.empty())
            continue;
        std::string delimiter = "|";
        std::size_t delimPos = line.find(delimiter);
        if(delimPos == std::string::npos)
        {
            std::cerr << "Error: Bad input => " << line << std::endl;
            continue;
        }
        std::string dateStr = trim(line.substr(0, delimPos));
        std::string valueStr = trim(line.substr(delimPos + delimiter.length()));

        if(!isValidDate(dateStr))
        {
            std::cerr << "Error: Invalid date => " << dateStr << std::endl;
            continue;
        }
        float value;
        if(!isValidValue(valueStr, value))
        {
            std::cerr << "Error: Invalid value => " << valueStr << std::endl;
            continue;
        }
        if(value < 0)
        {
            std::cerr << "Error: Negative value => " << value << std::endl;
            continue;
        }
        if(value > 1000)
        {
            std::cerr << "Error: Value too large => " << value << std::endl;
            continue;
        }
        std::map<std::string, float>::iterator it = _db.lower_bound(dateStr);
        if(it == _db.end())
        {
            --it;
        }
        else if (it->first != dateStr)
        {
            if(it == _db.begin())
            {
                std::cerr << "Error: bad input => " << dateStr
                    << " (date before database range)" << std::endl;
                continue;
            }
            --it;
        }
        float result = value * it->second;
        std::cout << dateStr << " => " << value << " = " << result << std::endl;
    }
}