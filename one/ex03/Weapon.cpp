
#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    _type = type.empty() ? "undefined weapon" : type;
}

Weapon::~Weapon() {}

void Weapon::setType(std::string type) {
    _type = type;
}

std::string Weapon::getType() const {
    return _type;
}
