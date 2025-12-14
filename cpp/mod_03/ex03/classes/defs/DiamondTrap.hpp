#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;

    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap& ref);
        DiamondTrap& operator=(const DiamondTrap& ref);
        ~DiamondTrap();

        DiamondTrap(const std::string& name);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        //void whoAmI();
};

#endif
