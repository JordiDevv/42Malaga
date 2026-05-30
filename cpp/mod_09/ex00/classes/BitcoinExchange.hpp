#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define ERR_NARGS "Error: you need to introduce only the input file as argument"
#define ERR_NINPUT "Error: input file couldn't be open"
#define ERR_INASOUT "Error: the database shouldn't be the input file"
#define ERR_SRCASOUT "Don't you dare"

#define ERR_BADINPUTLINE "Error: bad input => "
#define ERR_NOPOSN "Error: not a positive number"
#define ERR_TOOLARGEN "Error: too large number"

#include <string>
#include <map>

class BitcoinExchange
{
    private:
        int _year;
        int _month;
        int _day;
        float _value;

        std::map<std::string, int> data;

        int parseDateComp(size_t& i, const std::string& line);
        float parseValue(size_t& i, const std::string& line);
        bool isValidDay();
        bool errBadInput(const std::string& line);

    public:
        bool parseLine(const std::string& line);
};

#endif
