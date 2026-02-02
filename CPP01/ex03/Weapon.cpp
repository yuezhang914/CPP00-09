#include "Weapon.hpp"

Weapon::Weapon(const std::string &weaponType) : _type(weaponType)
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType(void) const
{
    return _type;
}

void Weapon::setType(const std::string &newType)
{
    _type = newType;
}
