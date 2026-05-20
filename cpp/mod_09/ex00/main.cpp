#include <fstream>
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "You need to introduce only the output data file as an argument" << std::endl;
        return 1;
    }
    if (std::string(argv[1]) == "data.csv")
    {
        std::cerr << "The input data shouldn't be the output file" << std::endl;
        return 1;
    }
    
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
