#include "msgs.h"
#include <iostream>

int main(int argc, char **argv)
{
    argv = argv;
    if (argc != 4)
        std::cout << RED << "The number of arguments is not correct." << RESET << std::endl;
}