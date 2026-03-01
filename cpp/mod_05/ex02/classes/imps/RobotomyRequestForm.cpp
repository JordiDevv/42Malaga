#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("default") {}

    RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref)
    : AForm(ref), target(ref.target) {}

    RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
    {
        if (this != &ref)
        {
            AForm::operator=(ref);
            this->target = ref.target;
        }
        return *this;
    }

    RobotomyRequestForm::~RobotomyRequestForm() {}
