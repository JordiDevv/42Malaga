#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
    private:
        int current_i;
        Contact contacts[8];

    public:
        PhoneBook();
        
        int getCurrentIndex();
        void increaseIndex();
        void resetIndex();

        void ADD(Contact new_contact);
};

#endif
