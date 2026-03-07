#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

typedef void (*ConverterFlows)(char* c, int* n, float* f);

class ScalarConverter
{
    private:
        ScalarConverter();

    public:
        static void convert(const std::string& literal);
};

#endif