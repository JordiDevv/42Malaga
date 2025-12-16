#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal
{
    private:
        Brain* brain;

    public:
        Dog();
        Dog(const Dog& ref);
        Dog& operator=(const Dog& ref);
        ~Dog();

        const std::string getType() const;

        void makeSound() const;
};

#endif
