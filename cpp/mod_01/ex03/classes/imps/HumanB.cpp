#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
    : name(name), weapon() {}

void HumanB::setWeapon(Weapon& weapon) { this->weapon = &weapon; }

void HumanB::attack()
{
    std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;
}
