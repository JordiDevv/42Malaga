#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    Intern::Intern() {}
    Intern::Intern(const Intern& ref) {}
    Intern& Intern::operator=(const Intern& ref) {}
    Intern::~Intern() {}


  // **************************************************** //
 //                   Forms factory                      //
// **************************************************** //

    AForm* createShrubberyCreation(const std::string& target)
    { return new ShrubberyCreationForm(target); }

    AForm* createRobotomyRequest(const std::string& target)
    { return new RobotomyRequestForm(target); }

    AForm* createPresidentialPardon(const std::string& target)
    { return new PresidentialPardonForm(target); }

    AForm* Intern::makeForm(const std::string& name, const std::string& target)
    {
        const std::string forms[3] =
        { "shrubbery creation", "robotomy request", "presidential pardon"};
        FormsFactory formCreationFuncs[3] =
        { createShrubberyCreation, createRobotomyRequest, createPresidentialPardon };
    }
