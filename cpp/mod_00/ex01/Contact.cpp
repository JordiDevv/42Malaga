#include "Contact.hpp"
#include <string>
using namespace std;

Contact::Contact(int i, const string &fn, const string &ln, const string &nn, int pn, const string &ds)
        : index(i), first_name(fn), last_name(ln), nickname(nn), phone_number(pn), darkest_secret(ds) {}

// int getIndex() const { return index; }
// string getFirstName() const { return first_name; }
// string getLastName() const { return last_name; }
// string getNickname() const { return nickname; }
// int getPhoneNumber() const { return phone_number; }
// string getDarkestSecret() const { return darkest_secret; }