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

    std::string outputFile(argv[1]);
    if (outputFile == "data.csv")
    {
        std::cerr << ERR_INASOUT << std::endl;
        return false;
    }

    std::string srcData[] =
    {"classes/BitcoinExchange.cpp", "classes/BitcoinExchange.hpp", "main.cpp", "Makefile"};
    size_t srcDataSize = sizeof(srcData) / sizeof(srcData[0]);
    for (size_t i = 0; i < srcDataSize; i++)
    {
        if (outputFile == srcData[i])
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
    std::string outputName(argv[1]);

    std::ofstream outputFile(outputName.c_str());
    std::ofstream meta(".output_name");
    meta << outputName;
    std::ifstream data("data.csv");

    std::string line;
    std::getline(data, line);
    while (std::getline(data, line))
    {
        BitcoinExchange btc;
        if (!btc.parseLine(line)) continue ;
    }

    outputFile.close();
    data.close();
    return 0;
}
