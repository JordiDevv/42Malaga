#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <set>
#include <fstream>

  // **************************************************** //
 //                     Validation                       //
// **************************************************** //

    bool BitcoinExchange::isValidDate(const std::string& date, char del)
    {
        size_t i = 0;

        int year = parseDateComp(i, date);
        if (year < 0 || year > 2025 || date[i++] != '-') return false;

        int month = parseDateComp(i, date);
        if (month < 1 || month > 12 || date[i++] != '-') return false;

        int day = parseDateComp(i, date);
        if (!isValidDay(day, month) || date[i++] != del) return false;

        return true;
    }

    int BitcoinExchange::parseDateComp(size_t& i, const std::string& date)
    {
        std::string rawComp;
        while (i < date.size() && isdigit(date[i])) rawComp.push_back(date[i++]);

        if (rawComp.empty()) return -1;

        long n = strtol(rawComp.c_str(), NULL, 10);
        return n;
    }

    bool BitcoinExchange::isValidDay(int day, int month)
    {
        if (day > 31) return false;
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
        if (month == 2 && day > 29) return false;
        return true;
    }

    float BitcoinExchange::parseValue(const std::string& rawValue)
    {
        if (rawValue.empty()) return -1;

        char* end;
        float value = strtof(rawValue.c_str(), &end);

        if (*end != '\0' || errno == ERANGE) return -1;

        return value;
    }

    bool BitcoinExchange::isValidInputLine(const std::string& line)
    {
        if (!isValidDate(line, ' ')) return errBadInput(line);
        
        size_t posDel = line.find(' ');
        if (line[++posDel] != '|') return errBadInput(line);
        if (line[++posDel] != ' ') return errBadInput(line);
        if (isspace(line[++posDel])) return errBadInput(line);

        float value = parseValue(line.substr(posDel));
        if (value < 0) return errNoPosN();
        if (value > 1000) return errTooLargeN();

        return true;
    }


  // **************************************************** //
 //                  Errors Handlers                     //
// **************************************************** //

    bool BitcoinExchange::errBadCsv(std::ifstream& data)
    {
        std::cerr << ERR_BADCSV << std::endl;
        data.close();
        return false;
    }

    bool BitcoinExchange::errBadInput(const std::string& line)
    {
        std::cerr << ERR_BADINPUTLINE << line << std::endl;
        return false;
    }

    bool BitcoinExchange::errNoPosN()
    {
        std::cerr << ERR_NOPOSN << std::endl;
        return false;
    }

    bool BitcoinExchange::errTooLargeN()
    {
        std::cerr << ERR_TOOLARGEN << std::endl;
        return false;
    }

    bool BitcoinExchange::errNoRecord(const std::string& line)
    {
        std::cerr << ERR_NORECORD << line << std::endl;
        return false;
    }


  // **************************************************** //
 //                      Parser                          //
// **************************************************** //

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
        if (!isValidDate(line, ',')) return false;

        size_t del = line.find(',');
        std::string date = line.substr(0, del);

        std::string rawEx = line.substr(del + 1);
        float ex = parseValue(rawEx);
        if (ex < 0) return false;

        _data.insert(std::make_pair(date, ex));

        return true;
    }


  // **************************************************** //
 //                  Public processors                   //
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

    void BitcoinExchange::processLine(const std::string& line)
    {
        if (!isValidInputLine(line)) return ;

        std::pair<std::string, float> parsedLine = parseInputLine(line);
        std::map<std::string, float>::iterator dataEntrance = _data.lower_bound(parsedLine.first);

        if (dataEntrance == _data.end())
            dataEntrance--;
        else if (dataEntrance->first != parsedLine.first)
        {
            if (dataEntrance == _data.begin()) errNoRecord(line);
            else --dataEntrance;
        }

        std::cout << parsedLine.first << " | " << parsedLine.second << std::endl;
        std::cout << dataEntrance->first << " | " << dataEntrance->second << std::endl;
    }
