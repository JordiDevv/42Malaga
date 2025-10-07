#include "PhoneBook.hpp"
#include "msgs.h"
#include <string.h>
#include <iostream>
#include <sstream>

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

static int prompt_in(int n_contacts)
{
    std::string input;
    int in;

    while (1)
    {
        std::cout.write(ENTIND_MSG, ENTIND_MSG_L);
        std::getline(std::cin, input);
        std::stringstream input_pars(input);

        if (!(input_pars >> in))
            continue;
        else
        {
            if (in >= 0 && in < n_contacts)
                return (in);
        }
    }
}

static void display_full_contact(const Contact& contact)
{
    display_column(contact.getFirstName(), false);
    display_column(contact.getLastName(), false);
    display_column(contact.getNickname(), false);
    display_column(contact.getPhoneNumber(), false);
    display_column(contact.getDarkestSecret(), true);
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

    int target_index = prompt_in(n_contacts);
    const Contact& contact = phonebook.getContactByIndex(target_index);
    display_full_contact(contact);
}
