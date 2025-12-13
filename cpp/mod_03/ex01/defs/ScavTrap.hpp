#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const ScavTrap& ref);
        ScavTrap& operator=(const ScavTrap& ref);
        ~ScavTrap();

        ScavTrap(const std::string& name);

        void attack(const std::string& target) override;
        void takeDamage(unsigned int amount) override;
        void beRepaired(unsigned int amount) override;
};

#endif
