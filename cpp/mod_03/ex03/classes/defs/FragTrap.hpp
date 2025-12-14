#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const FragTrap& ref);
        FragTrap& operator=(const FragTrap& ref);
        ~FragTrap();

        FragTrap(const std::string& name);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        void highFivesGuys();
};

#endif
