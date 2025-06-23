#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string typeIn):type(typeIn){}

Weapon::~Weapon(){}

std::string Weapon::getType() const {
	return this->type;
}

void Weapon::setType(const std::string &typeIn) {
	this->type = typeIn;
}