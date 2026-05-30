#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <set>
#include <fstream>

  // **************************************************** //
 //                   Parser utils                       //
// **************************************************** //

    bool BitcoinExchange::isValidDate(std::string date)
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

    int BitcoinExchange::parseDateComp(size_t& i, const std::string& line)
    {
        std::string rawComp;
        while (i < line.size() && line[i] != '-') rawComp.push_back(line[i++]);
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

    bool BitcoinExchange::isValidEx(std::string ex)
    {
        if (ex.empty()) return -1;

        char* end;
        strtof(ex.c_str(), &end);

        if (*end != '\0' || errno == ERANGE) return false;
        return true;
    }

    // float BitcoinExchange::parseValue(size_t& i, const std::string& line)
    // {
    //     std::string rawValue;
    //     while (i < line.size()) rawValue.push_back(line[i++]);
    //     if (rawValue.empty()) return -1;

    //     char* end;
    //     long n = strtol(rawValue.c_str(), &end, 10);

    //     if (*end != '\0' || errno == ERANGE) return -1;
    //     return n;
    // }


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

    // bool BitcoinExchange::parseLine(const std::string& line)
    // {
    //     size_t i = 0;

    //     _year = parseDateComp(i, line);
    //     if (_year < 2000 || _year > 2025) return errBadInput(line);

    //     _month = parseDateComp(i, line);
    //     if (_month < 1 || _month > 12) return errBadInput(line);

    //     _day = parseDateComp(i, line);
    //     if (!isValidDay()) return errBadInput(line);

    //     _value = parseValue(i, line);
    //     if (_value < 0 || _value > 1000) return errBadInput(line);

    //     return true;
    // }

    bool BitcoinExchange::parseCsvLine(std::string line)
    {
        size_t del = line.find(',');

        std::string date = line.substr(0, del);
        if (!isValidDate(date)) return false;

        std::string ex = line.substr(del + 1);
        if (!isValidEx(ex)) return false;

        // insert to the map

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
