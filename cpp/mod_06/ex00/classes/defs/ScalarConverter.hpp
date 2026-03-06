#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

typedef void (*ConverterFlows)(const std::string& literal, const std::string& type);

class ScalarConverter
{
    private:
        ScalarConverter();

    public:
        static void convert(const std::string& literal);
};

#endif