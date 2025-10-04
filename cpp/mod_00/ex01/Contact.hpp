#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        int phone_number;
        std::string darkest_secret;

    public:
        Contact();

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        int getPhoneNumber() const;
        std::string getDarkestSecret() const;
};

#endif
