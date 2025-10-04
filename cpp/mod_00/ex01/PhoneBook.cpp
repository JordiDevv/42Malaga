#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

int PhoneBook::getCurrentIndex() { return (current_i); }
void PhoneBook::increaseIndex() { current_i++; }
void PhoneBook::resetIndex() { current_i = 0; }

// void PhoneBook::ADD(Contact new_contact)
// {
//     this.
// }