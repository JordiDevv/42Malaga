#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"
using namespace std;

class PhoneBook
{
    private:
        Contact contacts[8];

    public:
        PhoneBook(Contact contacts[8]);

        void ADD(Contact new_contact);
};

#endif
