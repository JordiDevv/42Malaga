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
    phonebook.initN();
    std::cout.write(WELCOME_MSG, WELCOME_MSG_L);

    while (1)
    {
        std::cout.write(CHS_MSG, CHS_MSG_L);
        std::getline(std::cin, input);

        if (input == "ADD") ft_add(phonebook);
        else if (input == "SEARCH") ft_search(phonebook);
        else if (input == "EXIT") break;
    }

    std::cout.write(EXIT_MSG, EXIT_MSG_L);
    return (0);
}
