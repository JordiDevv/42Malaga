#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "msgs.h"
#include <iostream>

void ft_add(PhoneBook &phonebook)
{
    std::string input;
    int i = phonebook.getCurrentIndex();

    while (1)
    {
        std::cout.write(FN_MSG, FN_MSG_L);
        std::getline(std::cin, input);
        if (input != "")
            break;
    }
    std::cout.write(ADDED_MSG, ADDED_MSG_L);
}