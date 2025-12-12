#include "ClapTrap.hpp"

   // **************************************************** //
  //              Cannonical implementations              //
 // **************************************************** //

    ClapTrap();
    ClapTrap(const ClapTrap& ref);
    ClapTrap& operator=(const ClapTrap& ref);
    ~ClapTrap();


   // **************************************************** //
  //        Constructors for parameterized values         //
 // **************************************************** //

    ClapTrap(const std::string name);


   // **************************************************** //
  //                  Combat functions                    //
 // **************************************************** //

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
