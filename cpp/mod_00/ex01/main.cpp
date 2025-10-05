#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "msgs.h"
#include <iostream>

int main()
{
    PhoneBook phonebook;
    phonebook.resetIndex();
    std::cout.write(WELCOME_MSG, WELCOME_MSG_L);
}