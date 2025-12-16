#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat& ref);
        WrongCat& operator=(const WrongCat& ref);
        ~WrongCat();
    
        const std::string getType() const;
};

#endif
