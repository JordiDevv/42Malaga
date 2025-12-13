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

    void ClapTrap::attack(const std::string& target)
    {
        if (!canTakeAction()) return printState();

        std::cout << RED << "ClapTrap" << name << "attacks" << target << ", causing"
            << attackDamage << "points of damage!" << RESET << std::endl;
        energy--;
    }

    void ClapTrap::takeDamage(unsigned int amount)
    {
        std::cout << RED << "ClapTrap" << name << "received " << amount
            << " points of damage!" << RESET << std::endl;
        health -= amount;
    }

    void ClapTrap::beRepaired(unsigned int amount)
    {
        if (!canTakeAction()) return printState();

        std::cout << RED << "ClapTrap" << name << "restore " << amount
             << "points of life!" << RESET << std::endl;

        health += amount;
        energy--;
    }


   // **************************************************** //
  //                  State functions                     //
 // **************************************************** //

    bool ClapTrap::canTakeAction() { return health > 0 && energy > 0; }

    void ClapTrap::printState()
    {
        if (this->health <= 0)
            std::cout << YELLOW << NO_HE << RESET << std::endl;
        else if (this->energy <= 0)
            std::cout << YELLOW << NO_EN << RESET << std::endl;
        return ;
    }
