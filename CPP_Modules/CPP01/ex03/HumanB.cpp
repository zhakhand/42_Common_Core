#include "HumanB.hpp"

HumanB::HumanB() {}

HumanB::HumanB(std::string nameIn) : name(nameIn), weapon(NULL) {}

HumanB::HumanB(std::string nameIn, Weapon &weaponIn) : name(nameIn), weapon(&weaponIn){}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon &weaponIn) {
	this->weapon = &weaponIn;
}

void HumanB::attack() {
	std::cout << this->name << " attacks with their " 
	<< ((this->weapon == NULL) ? "WHAT?" : (*this->weapon).getType()) << "\n";
}