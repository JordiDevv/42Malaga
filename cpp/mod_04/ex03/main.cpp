#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
    AMateria* floor[2];

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    floor[0] = tmp;
    tmp = src->createMateria("cure");
    me->equip(tmp);
    floor[1] = tmp;

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    me->unequip(0);
    me->unequip(1);

    delete bob;
    delete me;
    delete src;

    for (int i = 0; i < 2; i++)
        delete floor[i];

    return 0;
}
