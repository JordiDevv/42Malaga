#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <set>

  // **************************************************** //
 //                   Parser utils                       //
// **************************************************** //

    int BitcoinExchange::parseDateComp(size_t& i, const std::string& line)
    {
        std::string rawComp;
        while (i < line.size() && line[i] != '-' && line[i] != ',') rawComp.push_back(line[i++]);
        if (rawComp.empty()) return 0;

        char* end;
        long n = strtol(rawComp.c_str(), &end, 10);

        if (*end != '\0' || errno == ERANGE) return 0;
        return n;
    }

    bool BitcoinExchange::isValidDay()
    {
        if (_day > 31) return false;
        if ((_month == 4 || _month == 6 || _month == 9 || _month == 11) && _day > 30) return false;
        if (_month == 2 && _day > 29) return false;
        return true;
    }

  // **************************************************** //
 //                  Errors Handlers                     //
// **************************************************** //

    bool BitcoinExchange::errBadInput(const std::string& line)
    {
        std::cerr << ERR_BADINPUTLINE << line << std::endl;
        return false;
    }


  // **************************************************** //
 //                      Parser                          //
// **************************************************** //

    bool BitcoinExchange::parseLine(const std::string& line)
    {
        size_t i = 0;

        _year = parseDateComp(i, line);
        if (_year < 2009 || _year > 2025) return errBadInput(line);
        i++;

        _month = parseDateComp(i, line);
        if (_month < 1 || _month > 12) return errBadInput(line);
        i++;

        _day = parseDateComp(i, line);
        if (!isValidDay()) return errBadInput(line);
        i++;

        return true;
    }
