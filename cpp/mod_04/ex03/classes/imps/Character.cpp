#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include <iostream>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    Character::Character() { for (int i = 0; i < 4; i++) inventory[i] = nullptr; }

    Character::Character(const Character& ref) : name(ref.name)
    {
        for (int i = 0; i < 4; i++)
        {
            if (ref.inventory[i])
                this->inventory[i] = ref.inventory[i]->clone();
            else
                this->inventory[i] = nullptr;
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
                this->inventory[i] = nullptr;
                if (ref.inventory[i])
                    this->inventory[i] = ref.inventory[i]->clone();
            }
        }
        return *this;
    }

    Character::~Character() { for (int i = 0; i < 4; i++) delete inventory[i]; }


  // **************************************************** //
 //                   Virtual Methods                    //
// **************************************************** //

    // AMateria* Cure::clone() const { return new Cure(); }
    // void Cure::use(ICharacter& target)
    // { std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl; }
