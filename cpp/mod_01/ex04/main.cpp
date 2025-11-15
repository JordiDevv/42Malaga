#include "msgs.h"
#include <iostream>
#include <fstream>

void replace_text(std::ifstream& file, std::ofstream& new_file, const std::string& s1, const std::string& s2)
{
    std::string line;
    while (std::getline(file, line))
    {
        std::string new_line;
        size_t pos = 0;

        while (true)
        {
            size_t found = line.find(s1, pos);
            if (found == std::string::npos)
            {
                new_line += line.substr(pos);
                break;
            }

            new_line += line.substr(pos, found - pos);
            new_line += s2;
            pos = found + s1.size();
        }

        new_file << new_line << '\n';
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << RED << "The number of arguments is not correct." << RESET << std::endl;
        return (1);
    }
    if (!argv[2][0])
    {
        std::cout << RED << "One of the strings are empty." << RESET << std::endl;
        return (1);
    }
    
    std::string filename = argv[1];
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cout << RED << "Error opening the file." << RESET << std::endl;
        return (1);
    }
    std::string new_name = filename + ".replace";
    std::ofstream new_file(new_name.c_str());
    if (!new_file)
    {
        std::cout << RED << "Error creating the file." << RESET << std::endl;
        return (1);
    }

    std::string s1 = argv[2];
    std::string s2 = argv[3];

    replace_text(file, new_file, s1, s2);
    file.close();
    new_file.close();
}
