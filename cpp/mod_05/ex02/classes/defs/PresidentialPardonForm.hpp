#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& ref);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);
        ~PresidentialPardonForm();
};

#endif