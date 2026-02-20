#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137) {}

    ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref)
    : AForm(ref) {}

    ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
    {
        if (this != &ref) AForm::operator=(ref);
        return *this;
    }

    ShrubberyCreationForm::~ShrubberyCreationForm() {}
