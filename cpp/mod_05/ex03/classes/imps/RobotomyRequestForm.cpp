#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>
#include <cstdlib>

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


  // **************************************************** //
 //              Parameterized constructors              //
// **************************************************** //

    RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}


  // **************************************************** //
 //                  Actions methods                     //
// **************************************************** //

    void RobotomyRequestForm::executeBehaviour() const
    {
        std::cout << "*Some drilling noises*" << std::endl;
        if (rand() % 2) std::cout << target << " has been robotomized." << std::endl;
        else std::cout << "Robotomy failed." << std::endl;
    }
