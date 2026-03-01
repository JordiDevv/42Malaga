#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& ref);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);
        ~RobotomyRequestForm();
};

#endif