#include "ClapTrap.hpp"
#include "msgs.h"
#include <iostream>

int main()
{
    ClapTrap clapRonnie("Ronnie");
    ClapTrap clapJames("James");

    std::cout << BLUE << INT_MSG << RESET << std::endl;
    std::cout << BLUE << BEG_MSG << RESET << std::endl;

    clapRonnie.attack(clapJames.getName());
    clapJames.takeDamage(clapRonnie.getAttackDamage());
    clapRonnie.attack(clapRonnie.getName());
    clapJames.takeDamage(clapJames.getAttackDamage());
    clapRonnie.attack(clapJames.getName());
    clapJames.takeDamage(clapRonnie.getAttackDamage());
    clapRonnie.attack(clapRonnie.getName());
    clapJames.takeDamage(clapJames.getAttackDamage());

    std::cout << BLUE << MID_MSG << RESET << std::endl;
    clapRonnie.beRepaired(0);
    std::cout << BLUE << PLOT_MSG << RESET << std::endl;

    ClapTrap *clapRandom = new ClapTrap();
    delete clapRandom;

    std::cout << BLUE << APO_MSG << RESET << std::endl;
    ClapTrap clapOne(clapJames);
    ClapTrap clapTwo(clapRonnie);
    ClapTrap clapThree(clapJames);
    ClapTrap clapFour(clapRonnie);
    ClapTrap clapFive(clapJames);
    ClapTrap clapSix(clapRonnie);
    
    std::cout << BLUE << END_MSG << RESET << std::endl;
    return 0;
}
