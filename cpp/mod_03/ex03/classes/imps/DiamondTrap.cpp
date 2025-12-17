#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "msgs.h"
#include <iostream>

   // **************************************************** //
  //              Cannonical implementations              //
 // **************************************************** //

    DiamondTrap::DiamondTrap()
    {
        energy = 50;
        attackDamage = 30;
        std::cout << BLUE << DEFDIA_CALL << RESET << std::endl;
    }

    DiamondTrap::DiamondTrap(const DiamondTrap& ref)
    : ClapTrap(ref), ScavTrap(ref), FragTrap(ref), name(ref.name)
    { std::cout << BLUE << this->name << DIA_CALL << RESET << std::endl; }

    DiamondTrap& DiamondTrap::operator=(const DiamondTrap& ref)
    {
        if (this != &ref)
        {
            ClapTrap::operator=(ref);
            ScavTrap::operator=(ref);
            FragTrap::operator=(ref);
            this->name = ref.name;
        }

        return *this;
    }

    DiamondTrap::~DiamondTrap()
    {
        if (this->name.size())
            std::cout << BLUE << this->name << DIA_BYE << RESET << std::endl;
        else
            std::cout << BLUE << DEFDIA_BYE << RESET << std::endl;
    }


   // **************************************************** //
  //        Constructors for parameterized values         //
 // **************************************************** //

    DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
    {
        energy = 50;
        attackDamage = 30;
        std::cout << BLUE << this->name << DIA_CALL << RESET << std::endl;
    }


   // **************************************************** //
  //             Overriden Combat functions               //
 // **************************************************** //

    void DiamondTrap::attack(const std::string& target)
    { ScavTrap::attack(target); }

    void DiamondTrap::takeDamage(unsigned int amount)
    { ScavTrap::takeDamage(amount); }

    void DiamondTrap::beRepaired(unsigned int amount)
    { ScavTrap::beRepaired(amount); }


   // **************************************************** //
  //              Existentialist functions                //
 // **************************************************** //

    void DiamondTrap::whoAmI()
    { std::cout << BLUE << "I am " << name << " son of " << ClapTrap::name << RESET << std::endl; }
