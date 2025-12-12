#include "Harl.hpp"
#include "msgs.h"
#include <iostream>

Harl::Harl() {}

void Harl::debug(void) { std::cout << GREY << DEBUG_MSG << RESET << std::endl; }
void Harl::info(void) { std::cout << GREY << INFO_MSG << RESET << std::endl; }
void Harl::warning(void) { std::cout << GREY << WARN_MSG << RESET << std::endl; }
void Harl::error(void) { std::cout << GREY << ERR_MSG << RESET << std::endl; }

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*functions[])() =
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    int i;
    for (i = 0; i < 4; i++)
        if (levels[i] == level) break;

    switch (i)
    {
        case 0:
            (this->*functions[0])();
            // Fall through
        case 1:
            (this->*functions[1])();
            // Fall through
        case 2:
            (this->*functions[2])();
            // Fall through
        case 3:
            (this->*functions[3])();
            break;
        default:
            std::cout << YELLOW << NO_COM << RESET;
            break;
    }
}
