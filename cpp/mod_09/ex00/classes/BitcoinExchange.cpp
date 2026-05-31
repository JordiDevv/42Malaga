#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <set>
#include <fstream>

  // **************************************************** //
 //                   Parser utils                       //
// **************************************************** //

    bool BitcoinExchange::isValidDate(const std::string& date)
    {
        size_t i = 0;

        int year = parseDateComp(i, date);
        if (year < 2000 || year > 2025) return false;

        int month = parseDateComp(i, date);
        if (month < 1 || month > 12) return false;

        int day = parseDateComp(i, date);
        if (!isValidDay(day, month)) return false;

        return true;
    }

    int BitcoinExchange::parseDateComp(size_t& i, const std::string& date)
    {
        std::string rawComp;
        while (i < date.size() && date[i] != '-') rawComp.push_back(date[i++]);
        i++;
        if (rawComp.empty()) return -1;

        char* end;
        long n = strtol(rawComp.c_str(), &end, 10);

        if (*end != '\0' || errno == ERANGE) return -1;
        return n;
    }

    bool BitcoinExchange::isValidDay(int day, int month)
    {
        if (day > 31) return false;
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
        if (month == 2 && day > 29) return false;
        return true;
    }

    bool BitcoinExchange::isValidEx(const std::string& ex)
    {
        if (ex.empty()) return false;

        char* end;
        strtof(ex.c_str(), &end);

        if (*end != '\0' || errno == ERANGE) return false;
        return true;
    }

    bool BitcoinExchange::isValidValue(const std::string& rawValue)
    {
        if (rawValue.empty()) return false;

        char* end;
        float value = strtof(rawValue.c_str(), &end);

        if (*end != '\0' || errno == ERANGE) return false;
        if (value < 0 || value > 1000) return false;

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

    bool BitcoinExchange::errBadCsv(std::ifstream& data)
    {
        std::cerr << ERR_BADCSV << std::endl;
        data.close();
        return false;
    }


  // **************************************************** //
 //                      Parser                          //
// **************************************************** //

    bool BitcoinExchange::isValidInputLine(const std::string& line)
    {
        if (!isValidDate(line)) return false;

        size_t posDel = line.find('|');
        if (!isValidValue(line.substr(posDel))) return false;

        return true;
    }

    std::pair<std::string, float> BitcoinExchange::parseInputLine(const std::string& line)
    {
        size_t posDel = line.find('|');

        std::string date = line.substr(0, posDel - 1);

        std::string rawValue = line.substr(posDel + 1);
        float value = strtof(rawValue.c_str(), NULL);

        return std::make_pair(date, value);
    }

    bool BitcoinExchange::parseCsvLine(const std::string& line)
    {
        size_t del = line.find(',');

        std::string date = line.substr(0, del);
        if (!isValidDate(date)) return false;

        std::string rawEx = line.substr(del + 1);
        if (!isValidEx(rawEx)) return false;
        float ex = strtof(rawEx.c_str(), NULL);

        _data.insert(std::make_pair(date, ex));

        return true;
    }


  // **************************************************** //
 //                     Load CSV                         //
// **************************************************** //

    bool BitcoinExchange::loadCsv(const std::string& dataName)
    {
        std::ifstream data(dataName.c_str());

        std::string line;
        std::getline(data, line);
        while (std::getline(data, line))
            if (!parseCsvLine(line)) return errBadCsv(data);
        data.close();
        return true;
    }

    bool BitcoinExchange::processLine(const std::string& line)
    {
        if (!isValidInputLine(line)) return errBadInput(line);
        return true;
    }
