#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

int PhoneBook::getCurrentIndex() { return (current_i); }
void PhoneBook::increaseIndex() { current_i++; }
void PhoneBook::resetIndex() { current_i = 0; }

void PhoneBook::ADD(const std::string& fn, const std::string& ln, const std::string& nn, int pn, const std::string& ds)
{
    int i = PhoneBook::getCurrentIndex();
    //contacts[i] = new_contact;
    PhoneBook::increaseIndex();
}
