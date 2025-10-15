#include "Weapon.hpp"
#include "string"

Weapon::Weapon() { type = "Fists"; }
Weapon::Weapon(std::string type) { this->type = type; }

const std::string& Weapon::getType() const { return (type); }
void Weapon::setType(const std::string& type) { this->type = type; }
