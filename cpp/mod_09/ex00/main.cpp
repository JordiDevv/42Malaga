#include <fstream>
#include <iostream>

bool validArgs(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "You need to introduce only the output data file as an argument" << std::endl;
        return false;
    }

    std::string outputFile(argv[1]);
    if (outputFile == "data.csv")
    {
        std::cerr << "The input data shouldn't be the output file" << std::endl;
        return false;
    }

    std::string srcData[] =
    {"classes/BitcoinExchange.cpp", "classes/BitcoinExchange.hpp", "main.cpp", "Makefile"};
    size_t srcDataSize = sizeof(srcData) / sizeof(srcData[0]);
    for (size_t i = 0; i < srcDataSize; i++)
    {
        if (outputFile == srcData[i])
        {
            std::cerr << "Don't you dare" << std::endl;
            return false;
        }
    }

    return true;
}

int main(int argc, char** argv)
{
    if (!validArgs(argc, argv)) return 1;
    
    std::ofstream outputData(argv[1]);
    std::ifstream data("data.csv");

    std::string line;
    while (std::getline(data, line))
    {
        // procesar linea
    }

    outputData.close();
    data.close();
    return 0;
}
