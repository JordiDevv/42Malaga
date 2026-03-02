#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));

    Intern intern;
    AForm* shu;
    AForm* robo;
    AForm* presi;
    Bureaucrat ronnie("Ronnie Radke", 1);

    shu = intern.makeForm("shrubbery creation", "coconut");
    robo = intern.makeForm("robotomy request", "Pedro Sánchez");
    presi = intern.makeForm("fake form", "Jim Carrey");
    presi = intern.makeForm("presidential pardon", "Puigdemont");

    ronnie.executeForm(*shu);
    ronnie.executeForm(*robo);
    ronnie.executeForm(*presi);

    delete shu;
    delete robo;
    delete presi;

    return 0;
}
