#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define ERR_NARGS "Error: you need to introduce only the input file as argument"
#define ERR_NINPUT "Error: input file couldn't be open"
#define ERR_INASOUT "Error: the database shouldn't be the input file"
#define ERR_SRCASOUT "Don't you dare"

#define ERR_BADCSV "Error: The csv database has a bad format"
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

        std::map<std::string, float> _data;

        bool parseCsvLine(const std::string& line);

        bool isValidDate(const std::string& date);
        int parseDateComp(size_t& i, const std::string& line);
        bool isValidDay(int day, int month);
        bool isValidEx(const std::string& ex);

        //float parseValue(size_t& i, const std::string& line);

        bool errBadCsv(std::ifstream& data);
        bool errBadInput(const std::string& line);

    public:
        //bool parseLine(const std::string& line);
        bool loadCsv(const std::string& dataName);
};

#endif
