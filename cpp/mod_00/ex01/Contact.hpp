#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
using namespace std;

class Contact
{
    private:
        int index;
        string first_name;
        string last_name;
        string nickname;
        int phone_number;
        string darkest_secret;

    public:
        Contact(int i, const string& fn, const string& ln, const string& nn, int pn, const string& ds);

        int getIndex() const { return index; }
        string getFirstName() const { return first_name; }
        string getLastName() const { return last_name; }
        string getNickname() const { return nickname; }
        int getPhoneNumber() const { return phone_number; }
        string getDarkestSecret() const { return darkest_secret; }
};

#endif
