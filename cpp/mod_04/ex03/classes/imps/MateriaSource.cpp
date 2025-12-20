#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

  // **************************************************** //
 //              Cannonical implementations              //
// **************************************************** //

    MateriaSource::MateriaSource() { for (int i = 0; i < 4; i++) materias[i] = NULL; }

    MateriaSource::MateriaSource(const MateriaSource& ref)
    {
        for (int i = 0; i < 4; i++)
        {
            if (ref.materias[i])
                this->materias[i] = ref.materias[i]->clone();
            else
                this->materias[i] = NULL;
        }
    }

    MateriaSource& MateriaSource::operator=(const MateriaSource& ref)
    {
        if (this != &ref)
        {
            for (int i = 0; i < 4; i++)
            {
                delete this->materias[i];
                this->materias[i] = NULL;
                if (ref.materias[i])
                    this->materias[i] = ref.materias[i]->clone();
            }
        }
        return *this;
    }

    MateriaSource::~MateriaSource() { for (int i = 0; i < 4; i++) delete materias[i]; }


  // **************************************************** //
 //               MateriaSource Interface                //
// **************************************************** //

    void MateriaSource::learnMateria(AMateria* m)
    {
        for (int i = 0; i < 4; i++)
        {
            if (!materias[i])
            {
                materias[i] = m->clone();
                break ;
            }
        }
    }

    AMateria* MateriaSource::createMateria(const std::string& type)
    {
        for (int i = 0; i < 4; i++)
        {
            if (materias[i] && materias[i]->getType() == type)
                return materias[i]->clone();
        }
        return NULL;
    }
    