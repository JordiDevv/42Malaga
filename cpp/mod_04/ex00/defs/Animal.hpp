#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
    protected:
        std::string type;
    
    public:
        Animal();
        Animal(const Animal& ref);
        Animal& operator=(const Animal& ref);
        ~Animal();

        virtual const std::string getType() const;

        virtual void makeSound();
};

#endif
