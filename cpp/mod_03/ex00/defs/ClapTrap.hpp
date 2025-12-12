#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap
{
    private:
        std::string name;
        int health = 10;
        int energy = 10;
        int attackDamage = 0;
    
    public:
        ClapTrap();
        ClapTrap(const ClapTrap& ref);
        ClapTrap& operator=(const ClapTrap& ref);
        ~ClapTrap();

        ClapTrap(const std::string& name);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
