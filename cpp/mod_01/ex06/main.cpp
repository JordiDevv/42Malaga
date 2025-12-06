#include "Harl.hpp"
#include "msgs.h"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "You can, and have, only introduce one complaining level" << std::endl;
        return (0);
    }

    Harl harl;
    harl.complain(argv[1]);
    return 0;
}
