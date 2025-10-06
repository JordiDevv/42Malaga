#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
    private:
        int current_i;
        int n_contacts;
        Contact contacts[8];

    public:
        PhoneBook();
        
        const int& getCurrentIndex() const;
        void increaseIndex();
        void resetIndex();

        void initN();
        int getN() const;

        void ADD(const std::string& fn, const std::string& ln, const std::string& nn, const std::string& pn, const std::string& ds);
        const Contact& getContactByIndex(int index) const;
        void SEARCH();
};

#endif
