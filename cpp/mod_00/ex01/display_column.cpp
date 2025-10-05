#include <iostream>
#include <string.h>
#include "msgs.h"

void display_column(std::string arg, bool last)
{
    if (arg.length() <= 10)
    {
        std::string spaces = std::string(" ", 10 - arg.length());
        std::cout << BLUE << spaces << arg.c_str() << RESET;
    }
    else
    {
        std::cout << BLUE;
        std::cout.write(arg.c_str(), 9);
        std::cout.put('.');
        std::cout << RESET;
    }
    if (!last)
        std::cout.put('|');
    else
        std::cout.put('\n');
}
