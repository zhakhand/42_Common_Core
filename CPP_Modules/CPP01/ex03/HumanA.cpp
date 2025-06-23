#include "HumanA.hpp"

HumanA::HumanA() {}

HumanA::HumanA(std::string nameIn, Weapon &weaponIn) : name(nameIn), weapon(&weaponIn){}

HumanA::~HumanA(){}

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << (*this->weapon).getType() << "\n";
}

