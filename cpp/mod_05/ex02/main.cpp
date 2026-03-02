#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));
    
    Bureaucrat pepe("Pepe", 150);
    Bureaucrat paco("Paco", 140);
    Bureaucrat pipo("Pipo", 50);
    Bureaucrat pedro("Pedro", 10);
    Bureaucrat arnold("Arnold", 1);

    ShrubberyCreationForm shu("my_awesome");
    RobotomyRequestForm robo("Pepe");
    PresidentialPardonForm pre("Oriol Junqueras");

    pepe.signForm(shu);
    paco.signForm(shu);
    pepe.executeForm(shu);
    paco.executeForm(shu);
    pipo.executeForm(shu);

    paco.signForm(robo);
    pipo.signForm(robo);
    paco.executeForm(robo);
    pipo.executeForm(robo);
    pedro.executeForm(robo);

    pipo.signForm(pre);
    pedro.signForm(pre);
    pipo.executeForm(pre);
    pedro.executeForm(pre);
    arnold.executeForm(pre);

    return 0;
}
