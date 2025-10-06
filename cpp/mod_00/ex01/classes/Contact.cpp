#include "Contact.hpp"
#include <string>

Contact::Contact() {}

const std::string& Contact::getFirstName() const { return first_name; }
const std::string& Contact::getLastName() const { return last_name; }
const std::string& Contact::getNickname() const { return nickname; }
const std::string& Contact::getPhoneNumber() const { return phone_number; }
const std::string& Contact::getDarkestSecret() const { return darkest_secret; }

void Contact::setFirstName(const std::string& fn) { first_name = fn; };
void Contact::setLastName(const std::string& ln) { last_name = ln; };
void Contact::setNickname(const std::string& nn) { nickname = nn; };
void Contact::setPhoneNumber(const std::string& pn) { phone_number = pn; };
void Contact::setDarkestSecret(const std::string& ds) { darkest_secret = ds; };
