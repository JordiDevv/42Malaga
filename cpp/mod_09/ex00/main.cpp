#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

bool validArgs(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << ERR_NARGS << std::endl;
        return false;
    }

    std::string inputFile(argv[1]);
    if (inputFile == "data.csv")
    {
        std::cerr << ERR_INASOUT << std::endl;
        return false;
    }

    std::string srcData[] =
    {"classes/BitcoinExchange.cpp", "classes/BitcoinExchange.hpp", "main.cpp", "Makefile"};
    size_t srcDataSize = sizeof(srcData) / sizeof(srcData[0]);
    for (size_t i = 0; i < srcDataSize; i++)
    {
        if (inputFile == srcData[i])
        {
            std::cerr << ERR_SRCASOUT << std::endl;
            return false;
        }
    }

    return true;
}

int main(int argc, char** argv)
{
    if (!validArgs(argc, argv)) return 1;
    std::string inputname(argv[1]);

    std::ifstream inputFile(inputname.c_str());
    if (!inputFile)
    {
        std::cerr << ERR_NINPUT << std::endl;
        return 1;
    }

    std::ofstream meta(".input_name");
    meta << inputname;

    BitcoinExchange btc;
    // loadData
    std::ifstream data("data.csv");

    std::string line;
    std::getline(inputFile, line);
    while (std::getline(inputFile, line))
    {
        if (!btc.parseLine(line)) continue ;
    }

    inputFile.close();
    data.close();
    return 0;
}
