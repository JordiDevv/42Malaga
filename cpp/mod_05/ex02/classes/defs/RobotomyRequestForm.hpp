#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& ref);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);
        ~RobotomyRequestForm();
};

#endif