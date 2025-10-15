#include "msgs.h"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << RED << "The number of arguments is not correct." << RESET << std::endl;
        return (1);
    }
    
    std::string filename = argv[1];
    std::fstream file(filename.c_str(), std::ios::in | std::ios::out);
    if (!file)
    {
        std::cout << RED << "Error opening the file." << RESET << std::endl;
        return (1);
    }

    std::string s1 = argv[2];
    std::string s2 = argv[3];

    file.close();
}