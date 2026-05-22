#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define ERR_NARGS "Error: you need to introduce only the output data file as an argument"
#define ERR_INASOUT "Error: the input data shouldn't be the output file"
#define ERR_SRCASOUT "Don't you dare"

#define ERR_BADINPUTLINE "Error: bad input => "
#define ERR_NOPOSN "Error: not a positive number"
#define ERR_TOOLARGEN "Error: too large number"

#include <string>

class BitcoinExchange
{
    private:
        int _year;
        int _month;
        int _day;
        float _value;

        int parseDateComp(size_t& i, const std::string& line);
        float parseValue(size_t& i, const std::string& line);
        bool isValidDay();
        bool errBadInput(const std::string& line);

    public:
        bool parseLine(const std::string& line);
};

#endif
