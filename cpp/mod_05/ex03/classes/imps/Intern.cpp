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
    Intern::Intern(const Intern& ref) { (void)ref; }
    Intern& Intern::operator=(const Intern& ref) { (void)ref; return *this; }
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
        FormsFactory formsCreators[3] =
        { createShrubberyCreation, createRobotomyRequest, createPresidentialPardon };

        for (int i = 0; i < 3; i++)
        {
            if (name == forms[i])
            {
                AForm *newForm = formsCreators[i](target);
                std::cout << "Intern has created " << newForm->getName() << std::endl;
                return newForm;
            }
        }

        std::cerr << "That's not one of our forms" << std::endl;
        return NULL;
    }
