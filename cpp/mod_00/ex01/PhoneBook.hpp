#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
    private:
        int current_i = 0;
        Contact contacts[8];

    public:
        PhoneBook(Contact contacts[8]);

        void ADD(Contact new_contact);
};

#endif
