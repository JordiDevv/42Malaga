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
};

#endif
