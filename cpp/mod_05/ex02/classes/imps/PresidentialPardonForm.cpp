#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5) {}

    PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref)
    : AForm(ref) {}

    PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
    {
        if (this != &ref) AForm::operator=(ref);
        return *this;
    }

    PresidentialPardonForm::~PresidentialPardonForm() {}
