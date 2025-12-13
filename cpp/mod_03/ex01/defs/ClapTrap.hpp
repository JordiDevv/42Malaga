#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap
{
    protected:
        std::string name;
        int health;
        int energy;
        int attackDamage;
    
    public:
        ClapTrap();
        ClapTrap(const ClapTrap& ref);
        ClapTrap& operator=(const ClapTrap& ref);
        ~ClapTrap();

        ClapTrap(const std::string& name);

        virtual void attack(const std::string& target);
        virtual void takeDamage(unsigned int amount);
        virtual void beRepaired(unsigned int amount);

        bool canTakeAction();
        void printState();

        const std::string& getName() const;
        const int& getAttackDamage() const;
};

#endif
