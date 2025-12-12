#include "ClapTrap.hpp"
#include "msgs.h"
#include <iostream>

   // **************************************************** //
  //              Cannonical implementations              //
 // **************************************************** //

    ClapTrap::ClapTrap() { std::cout << BLUE << DEF_CALL << RESET << std::endl; }

    ClapTrap::ClapTrap(const ClapTrap& ref)
    : name(name), health(health), energy(energy), attackDamage(attackDamage)
    { std::cout << this->name << BLUE << CALL << RESET << std::endl; }

    ClapTrap& ClapTrap::operator=(const ClapTrap& ref)
    {
        if (this != &ref)
        {
            this->name = ref.name;
            this->health = ref.health;
            this->energy = ref.energy;
            this->attackDamage = ref.attackDamage;
        }

        return *this;
    }

    ClapTrap::~ClapTrap()
    {
        if (this->name.size())
            std::cout << BLUE << BYE << this->name << RESET << std::endl;
        else
            std::cout << BLUE << DEF_BYE << RESET << std::endl;
    }


   // **************************************************** //
  //        Constructors for parameterized values         //
 // **************************************************** //

    ClapTrap::ClapTrap(const std::string& name) : name(name) {}


   // **************************************************** //
  //                  Combat functions                    //
 // **************************************************** //

    void attack(const std::string& target)
    {

    }

    void takeDamage(unsigned int amount)
    {

    }

    void beRepaired(unsigned int amount)
    {

    }

    //ClapTrap <name> attacks <target>, causing <damage> points of damage!
