#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45) {}

    RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref)
    : AForm(ref) {}

    RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
    {
        if (this != &ref) AForm::operator=(ref);
        return *this;
    }

    RobotomyRequestForm::~RobotomyRequestForm() {}
