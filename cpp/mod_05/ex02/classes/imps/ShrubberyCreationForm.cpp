#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("default") {}

    ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref)
    : AForm(ref), target(ref.target) {}

    ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
    {
        if (this != &ref)
        {
            AForm::operator=(ref);
            this->target = ref.target;
        }
        return *this;
    }

    ShrubberyCreationForm::~ShrubberyCreationForm() {}


  // **************************************************** //
 //              Parameterized constructors              //
// **************************************************** //

    ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}
