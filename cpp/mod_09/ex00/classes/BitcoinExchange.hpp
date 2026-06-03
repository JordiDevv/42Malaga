#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define ERR_NARGS "Error: you need to introduce only the input file as argument"
#define ERR_NINPUT "Error: input file couldn't be open"
#define ERR_INASOUT "Error: the database shouldn't be the input file"
#define ERR_SRCASOUT "Don't you dare"

#define ERR_BADCSV "Error: the csv database has a bad format"
#define ERR_BADINPUTLINE "Error: bad input => "
#define ERR_NOPOSN "Error: not a positive number"
#define ERR_TOOLARGEN "Error: too large number"
#define ERR_NORECORD "Error: there were no records of Bitcoin in the caveman era"

#include <string>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;

        // Validation
        bool isValidDate(const std::string& date, char del);
        int parseDateComp(size_t& i, const std::string& line);
        bool isValidDay(int day, int month);
        float parseValue(const std::string& value);
        bool isValidInputLine(const std::string& line);

        // Error handlers
        bool errBadCsv(std::ifstream& data);
        bool errBadInput(const std::string& line);
        bool errNoPosN();
        bool errTooLargeN();
        float errNoRecord();

        // Parser
        bool parseCsvLine(const std::string& line);
        std::pair<std::string, float> parseInputLine(const std::string& line);

        // Utils
        float getExchange(std::pair<std::string, float> parsedLine);

    public:
        // Public processors
        bool loadCsv(const std::string& dataName);
        void processLine(const std::string& line);
};

#endif
