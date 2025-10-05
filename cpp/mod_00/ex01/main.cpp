#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "msgs.h"
#include "utils.h"
#include <iostream>

int main()
{
    PhoneBook phonebook;
    std::string input;

    phonebook.resetIndex();
    std::cout.write(WELCOME_MSG, WELCOME_MSG_L);

    while (1)
    {
        std::cout.write(CHS_MSG, CHS_MSG_L);
        std::getline(std::cin, input);

        if (input == "ADD")
            ft_add(phonebook);
        else if (input == "SEARCH") std::cout.write("Funciona\n", 10);
        else if (input == "EXIT") break;
    }

    return (0);
}