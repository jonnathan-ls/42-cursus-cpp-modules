
#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {}

HumanB::~HumanB() {}

void HumanB::attack() const {
    if (weapon) {
        std::cout << name << " attacks with their " 
            << weapon->getType() << std::endl;
    } else {
        std::cout << name << " has no weapon to attack with!" << std::endl;
    }
}

void HumanB::setWeapon(Weapon const &weapon) {
    this->weapon = &weapon;
}
