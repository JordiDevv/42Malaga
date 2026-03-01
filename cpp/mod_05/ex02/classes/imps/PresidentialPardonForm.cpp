#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), target(target) {}

    PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref)
    : AForm(ref), target(ref.target) {}

    PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
    {
        if (this != &ref)
        {
            AForm::operator=(ref);
            this->target = ref.target;
        }
        return *this;
    }

    PresidentialPardonForm::~PresidentialPardonForm() {}
