#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
using namespace std;

class Contact
{
    private:
        string first_name;
        string last_name;
        string nickname;
        int phone_number;
        string darkest_secret;

    public:
        Contact(const string& fn, const string& ln, const string& nn, int pn, const string& ds);

        string getFirstName() const;
        string getLastName() const;
        string getNickname() const;
        int getPhoneNumber() const;
        string getDarkestSecret() const;
};

#endif
