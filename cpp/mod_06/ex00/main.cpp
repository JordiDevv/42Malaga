#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "We need one arg. Exactly one" << std::endl;
        return 1;
    }
    std::string literal = argv[1];

    ScalarConverter::convert(literal);
    return 0;
}