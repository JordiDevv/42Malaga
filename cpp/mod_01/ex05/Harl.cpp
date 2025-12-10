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

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*functions[i])();
            return;
        }
    }
    std::cout << YELLOW << "Harl doesn't know this level." << RESET << std::endl;
}
