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
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cout << RED << "Error opening the file." << RESET << std::endl;
        return (1);
    }

    std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    file.close();
}
