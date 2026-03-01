#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& ref);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);
        ~PresidentialPardonForm();
};

#endif