#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &personName, Weapon &personWeapon)
    : _name(personName), _weapon(personWeapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack(void) const
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
