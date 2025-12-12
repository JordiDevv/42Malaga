#include "ClapTrap.hpp"
#include "msgs.h"
#include <iostream>

   // **************************************************** //
  //              Cannonical implementations              //
 // **************************************************** //

    ClapTrap::ClapTrap() { std::cout << DEF_CALL << std::endl; }

    ClapTrap::ClapTrap(const ClapTrap& ref)
    : name(name), health(health), energy(energy), attackDamage(attackDamage)
    { std::cout << this->name << CALL << std::endl; }

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
            std::cout << BYE << this->name << std::endl;
        else
            std::cout << DEF_BYE << std::endl;
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
