#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.h"

PhoneBook::PhoneBook() {}

int PhoneBook::getCurrentIndex() { return (current_i); }
void PhoneBook::increaseIndex() { current_i++; }
void PhoneBook::resetIndex() { current_i = 0; }

void PhoneBook::initN() { n_contacts = 0; }

void PhoneBook::ADD(const std::string& fn, const std::string& ln, const std::string& nn, const std::string& pn, const std::string& ds)
{
    int i = PhoneBook::getCurrentIndex();

    contacts[i].setFirstName(fn);
    contacts[i].setLastName(ln);
    contacts[i].setNickname(nn);
    contacts[i].setPhoneNumber(pn);
    contacts[i].setDarkestSecret(ds);

    if (i < 7)
        PhoneBook::increaseIndex();
    else
        PhoneBook::resetIndex();
    
    if (n_contacts < 8) n_contacts++;
}

void PhoneBook::SEARCH()
{
    std::string index;
    for (int i = 0; i < n_contacts; i++)
    {
        index = i + '0';
        display_column(index, false);
        display_column(contacts[i].getFirstName(), false);
        display_column(contacts[i].getLastName(), false);
        display_column(contacts[i].getNickname(), true);
    }
}
