#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
    protected:
        const std::string type;

    public:
        AMateria();
        AMateria(const AMateria& ref);
        AMateria& operator=(const AMateria& ref);
        virtual ~AMateria();

        AMateria(const std::string& type);

        const std::string& getType() const;

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif
