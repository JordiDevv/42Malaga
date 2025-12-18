#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
    protected:
        std::string type;
    
    public:
        AAnimal();
        AAnimal(const AAnimal& ref);
        AAnimal& operator=(const AAnimal& ref);
        virtual ~AAnimal();

        virtual const std::string getType() const;

        virtual void makeSound() const = 0;
};

#endif
