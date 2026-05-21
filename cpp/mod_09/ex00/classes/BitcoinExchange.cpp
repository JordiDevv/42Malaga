#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>
#include <cerrno>

  // **************************************************** //
 //                   Parser utils                       //
// **************************************************** //

    int BitcoinExchange::parseYear(size_t& i, const std::string& line)
    {
        std::string rawYear;
        while (i < line.size() && line[i] != '-') rawYear.push_back(line[i++]);
        if (rawYear.empty()) return 0;

        char* end;
        long n = strtol(rawYear.c_str(), &end, 10);

        if (*end != '\0' || errno == ERANGE) return 0;
        return n;
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
        while (i < line.size())
        {
            _year = parseYear(i, line);
            if (_year < 2009 || _year > 2025) return errBadInput(line);
        }

        return true;
    }
