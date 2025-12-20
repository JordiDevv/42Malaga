#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include <iostream>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    Character::Character() { for (int i = 0; i < 4; i++) inventory[i] = NULL; }

    Character::Character(const Character& ref) : name(ref.name)
    {
        for (int i = 0; i < 4; i++)
        {
            if (ref.inventory[i])
                this->inventory[i] = ref.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }

    Character& Character::operator=(const Character& ref)
    {
        if (this != &ref)
        {
            this->name = ref.name;

            for (int i = 0; i < 4; i++)
            {
                delete this->inventory[i];
                this->inventory[i] = NULL;
                if (ref.inventory[i])
                    this->inventory[i] = ref.inventory[i]->clone();
            }
        }
        return *this;
    }

    Character::~Character() { for (int i = 0; i < 4; i++) delete inventory[i]; }


  // **************************************************** //
 //                 Character Interface                  //
// **************************************************** //

    const std::string& Character::getName() const { return name; }

    void Character::equip(AMateria* m)
    { for (int i = 0; i < 4; i++) if (!inventory[i]) inventory[i] = m; }

    void Character::unequip(int idx)
    { if (inventory[idx]) inventory[idx] = NULL; }

    void Character::use(int idx, ICharacter& target)
    { if (inventory[idx]) inventory[idx]->use(target); }
