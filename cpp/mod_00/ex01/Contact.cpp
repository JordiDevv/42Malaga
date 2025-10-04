#include "Contact.hpp"
#include <string>

Contact::Contact(const std::string &fn, const std::string &ln, const std::string &nn, int pn, const std::string &ds)
        : first_name(fn), last_name(ln), nickname(nn), phone_number(pn), darkest_secret(ds) {}

std::string Contact::getFirstName() const { return first_name; }
std::string Contact::getLastName() const { return last_name; }
std::string Contact::getNickname() const { return nickname; }
int Contact::getPhoneNumber() const { return phone_number; }
std::string Contact::getDarkestSecret() const { return darkest_secret; }
