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

static std::string prompt_ln()
{
    std::string input;

    while (1)
    {
        std::cout.write(LN_MSG, LN_MSG_L);
        std::getline(std::cin, input);
        if (input != "")
            return (input);
    }
}

static std::string prompt_nn()
{
    std::string input;

    while (1)
    {
        std::cout.write(NN_MSG, NN_MSG_L);
        std::getline(std::cin, input);
        if (input != "")
            return (input);
    }
}

static std::string prompt_pn()
{
    std::string input;

    while (1)
    {
        std::cout.write(PN_MSG, PN_MSG_L);
        std::getline(std::cin, input);
        if (input != "")
            return (input);
    }
}

static std::string prompt_ds()
{
    std::string input;

    while (1)
    {
        std::cout.write(DS_MSG, DS_MSG_L);
        std::getline(std::cin, input);
        if (input != "")
            return (input);
    }
}

void ft_add(PhoneBook &phonebook)
{
    std::string fn = prompt_fn();
    std::string ln = prompt_ln();
    std::string nn = prompt_nn();
    std::string pn = prompt_pn();
    std::string ds = prompt_ds();

    phonebook.ADD(fn, ln, nn, pn, ds);
    std::cout.write(ADDED_MSG, ADDED_MSG_L);
}
