#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <string>

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* materias[4];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource& ref);
        MateriaSource& operator=(const MateriaSource& ref);
        ~MateriaSource();

        void learnMateria(AMateria* m);
        AMateria* createMateria(const std::string& type);
};

#endif
