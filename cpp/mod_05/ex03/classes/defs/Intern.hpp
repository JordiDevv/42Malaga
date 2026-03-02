#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern
{
    public:
        Intern();
        Intern(const Intern& ref);
        Intern& operator=(const Intern& ref);
        virtual ~Intern();

        AForm* makeForm(const std::string& name, const std::string& target);
};

#endif