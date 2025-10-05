#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "msgs.h"
#include <iostream>

static std::string prompt_fn()
{
    std::string input;

    while (1)
    {
        std::cout.write(FN_MSG, FN_MSG_L);
        std::getline(std::cin, input);
        if (input != "")
            return (input);
    }
}

void ft_add(PhoneBook &phonebook)
{
    int i = phonebook.getCurrentIndex();

    std::string fn = prompt_fn();
    std::cout.write(ADDED_MSG, ADDED_MSG_L);
}