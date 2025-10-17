#include "Harl.hpp"
#include "msgs.h"
#include <iostream>

int main()
{
    std::cout << GREEN << INT_MSG << RESET;

    std::string input;
    Harl harl;
    while (1)
    {
        std::getline(std::cin, input);
        if (input == "EXIT") break;

        harl.complain(input);
    }

    std::cout << GREEN << BYE_MSG << RESET;
    return 0;
}
