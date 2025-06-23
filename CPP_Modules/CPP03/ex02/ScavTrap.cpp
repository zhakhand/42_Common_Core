#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap Constructor has been called!\n";
	_hitPoints = 100;
	_energyPoints = 50;
	_atkDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "ScavTrap Constructor has been called!\n";
	_hitPoints = 100;
	_energyPoints = 50;
	_atkDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other._name) {
	if (*this == other)
		return;
	std::cout << "ScavTrap Copy Constructor has been called!\n";
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (*this == other)
		return *this;
	std::cout << "ScavTrap Copy Assignment operator has been called!\n";
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_atkDamage = other._atkDamage;
	return *this;
}

bool ScavTrap::operator==(const ScavTrap& other) {
	return _name == other._name && _hitPoints == other._hitPoints 
			&& _energyPoints == other._energyPoints && _atkDamage == other._atkDamage;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " is destroyed!\n";
}

void ScavTrap::attack(const std::string& target) {
	if (!this->canAct()) {
		std::cout << "ScavTrap " << _name << " can not act!\n";
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target 
				<< ", causing " << this->_atkDamage 
				<<  " points of damage!\n";
	this->_energyPoints--;
	status();
}

void ScavTrap::guardGate() {
	if (!this->canAct()) {
		std::cout << "ScavTrap " << _name << " can not act!\n";
	}
	std::cout << "ScavTrap " << _name << " is in Gatekeeper mode!\n";
}