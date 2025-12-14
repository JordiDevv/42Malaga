#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "msgs.h"
#include <iostream>

   // **************************************************** //
  //              Cannonical implementations              //
 // **************************************************** //

    ScavTrap::ScavTrap()
    { 
        health = 100;
        energy = 50;
        attackDamage = 20;
        std::cout << BLUE << DEFSCAV_CALL << RESET << std::endl;
    }

    ScavTrap::ScavTrap(const ScavTrap& ref) : ClapTrap(ref)
    { std::cout << BLUE << this->name << SCAV_CALL << RESET << std::endl; }

    ScavTrap& ScavTrap::operator=(const ScavTrap& ref)
    {
        if (this != &ref) { ClapTrap::operator=(ref); }
        return *this;
    }

    ScavTrap::~ScavTrap()
    {
        if (this->name.size())
            std::cout << BLUE << this->name << SCAV_BYE << RESET << std::endl;
        else
            std::cout << BLUE << DEFSCAV_BYE << RESET << std::endl;
    }


   // **************************************************** //
  //        Constructors for parameterized values         //
 // **************************************************** //

    ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
    {
        health = 100;
        energy = 50;
        attackDamage = 20;
        std::cout << BLUE << this->name << SCAV_CALL << RESET << std::endl;
    }


   // **************************************************** //
  //             Overriden Combat functions               //
 // **************************************************** //

    void ScavTrap::attack(const std::string& target)
    {
        if (!canTakeAction()) return printState();

        std::cout << PURP << "ScavTrap " << name << " attacks " << target << ", causing "
            << attackDamage << " points of damage!" << RESET << std::endl;
        energy--;
    }

    void ScavTrap::takeDamage(unsigned int amount)
    {
        std::cout << PURP << "ScavTrap " << name << " received " << amount
            << " points of damage!" << RESET << std::endl;
        health -= amount;
    }

    void ScavTrap::beRepaired(unsigned int amount)
    {
        if (!canTakeAction()) return printState();

        std::cout << PURP << "ScavTrap " << name << " restore " << amount
             << " points of life!" << RESET << std::endl;

        health += amount;
        energy--;
    }


   // **************************************************** //
  //                Own Combat functions                  //
 // **************************************************** //

    void ScavTrap::guardGate()
    { std::cout << PURP << (!name.empty() ? name : "Default ScavTrap")
        << " is now in Gate keeper mode" << RESET << std::endl; }
