#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "msgs.h"
#include <iostream>

   // **************************************************** //
  //              Cannonical implementations              //
 // **************************************************** //

    FragTrap::FragTrap()
    { 
        health = 100;
        energy = 100;
        attackDamage = 30;
        std::cout << BLUE << DEFFRAG_CALL << RESET << std::endl;
    }

    FragTrap::FragTrap(const FragTrap& ref) : ClapTrap(ref)
    { std::cout << BLUE << this->name << FRAG_CALL << RESET << std::endl; }

    FragTrap& FragTrap::operator=(const FragTrap& ref)
    {
        if (this != &ref) { ClapTrap::operator=(ref); }
        return *this;
    }

    FragTrap::~FragTrap()
    {
        if (this->name.size())
            std::cout << BLUE << this->name << FRAG_BYE << RESET << std::endl;
        else
            std::cout << BLUE << DEFFRAG_BYE << RESET << std::endl;
    }


   // **************************************************** //
  //        Constructors for parameterized values         //
 // **************************************************** //

    FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
    {
        health = 100;
        energy = 100;
        attackDamage = 30;
        std::cout << BLUE << this->name << FRAG_CALL << RESET << std::endl;
    }


   // **************************************************** //
  //             Overriden Combat functions               //
 // **************************************************** //

    void FragTrap::attack(const std::string& target)
    {
        if (!canTakeAction()) return printState();

        std::cout << PURP << "FragTrap " << name << " attacks " << target << ", causing "
            << attackDamage << " points of damage!" << RESET << std::endl;
        energy--;
    }

    void FragTrap::takeDamage(unsigned int amount)
    {
        std::cout << PURP << "FragTrap " << name << " received " << amount
            << " points of damage!" << RESET << std::endl;
        health -= amount;
    }

    void FragTrap::beRepaired(unsigned int amount)
    {
        if (!canTakeAction()) return printState();

        std::cout << PURP << "FragTrap " << name << " restore " << amount
             << " points of life!" << RESET << std::endl;

        health += amount;
        energy--;
    }


   // **************************************************** //
  //                Own Combat functions                  //
 // **************************************************** //

    void FragTrap::highFivesGuys()
    { std::cout << PURP << (!name.empty() ? name : "Default FragTrap")
        << " asks for a high five" << RESET << std::endl; }
