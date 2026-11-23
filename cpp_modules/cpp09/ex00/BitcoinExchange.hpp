#pragma once
# include <map>
# include <string>
 
class BitcoinExchange
{
    private:
        std::map<std::string, float> _db;
        bool loadDatabase(std::string const& csvPath);
        bool isValidDate(std::string const& date) const;
        bool isValidValue(std::string const& valueStr, float& outValue) const;

        std::string trim(std::string const& s) const;
    
    public:

        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const& other);
        BitcoinExchange& operator=(BitcoinExchange const& other);
        ~BitcoinExchange();

        void process(std::string const& inputPath);
};   