#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap("Default"), ScavTrap("Default") {
	std::cout << "DiamondTrap Constructor has been called!\n";
	_name = "Default";
	ClapTrap::_hitPoints = FragTrap::_hitPoints;
	ClapTrap::_energyPoints = ScavTrap::_energyPoints;
	ClapTrap::_atkDamage = FragTrap::_atkDamage;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	std::cout << "DiamondTrap String Constructor has been called!\n";
	_name = name;
	ClapTrap::_hitPoints = FragTrap::_hitPoints;
	ClapTrap::_energyPoints = ScavTrap::_energyPoints;
	ClapTrap::_atkDamage = FragTrap::_atkDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other._name + "_clap_name"), FragTrap(other), ScavTrap(other) {
	std::cout << "DiamondTrap Copy Constructor has been called!\n";
	_name = other._name;
	ClapTrap::_name = other.ClapTrap::_name;
	ClapTrap::_hitPoints = other.ClapTrap::_hitPoints;
	ClapTrap::_energyPoints = other.ClapTrap::_energyPoints;
	ClapTrap::_atkDamage = other.ClapTrap::_atkDamage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "DiamondTrap Copy Assignment operator has been called!\n";
	_name = other._name;
	ClapTrap::_name = other.ClapTrap::_name;
	ClapTrap::_hitPoints = other.ClapTrap::_hitPoints;
	ClapTrap::_energyPoints = other.ClapTrap::_energyPoints;
	ClapTrap::_atkDamage = other.ClapTrap::_atkDamage;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->DiamondTrap::_name << " is destroyed!\n";
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "I am " << this->DiamondTrap::_name << " son of " << this->ClapTrap::_name << "!\n";
}