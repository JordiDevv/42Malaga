#include "PhoneBook.hpp"
#include <iostream>
#include <string.h>
#include "msgs.h"

static void display_column(std::string arg, bool last)
{
    if (arg.length() <= 10)
    {
        std::string spaces = std::string(10 - arg.length(), ' ');
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

static void display_row(const Contact& contact, const std::string& index)
{
    display_column(index, false);
    display_column(contact.getFirstName(), false);
    display_column(contact.getLastName(), false);
    display_column(contact.getNickname(), true);
}

void ft_search(PhoneBook& phonebook)
{
    int n_contacts = phonebook.getN();
    std::string index;

    for (int i = 0; i < n_contacts; i++)
    {
        const Contact& contact = phonebook.getContactByIndex(i);
        index = i + '0';

        display_row(contact, index);
    }
}
