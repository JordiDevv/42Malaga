#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "msgs.h"
#include <iostream>

int main()
{
    PhoneBook phonebook;
    std::string cmd;

    phonebook.resetIndex();
    std::cout.write(WELCOME_MSG, WELCOME_MSG_L);

    while (1)
    {
        std::getline(std::cin, cmd);
        if (cmd == "ADD")
        {
            std::cout.write("Funciona", 9);
            break;
        }
    }

    return (0);
}