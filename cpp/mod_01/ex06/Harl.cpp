#include "Harl.hpp"
#include "msgs.h"
#include <iostream>

Harl::Harl() {}

void Harl::debug(void) { std::cout << GREY << "[DEBUG] message." << RESET << std::endl; }
void Harl::info(void) { std::cout << GREY << "[INFO] message." << RESET << std::endl; }
void Harl::warning(void) { std::cout << GREY << "[WARNING] message." << RESET << std::endl; }
void Harl::error(void) { std::cout << GREY << "[ERROR] message." << RESET << std::endl; }

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
