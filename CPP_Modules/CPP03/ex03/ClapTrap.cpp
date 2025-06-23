#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _atkDamage(0) {
	std::cout << "ClapTrap Constructor has been called\n";
}

ClapTrap::ClapTrap(const std::string& name) :_hitPoints(10), _energyPoints(10), _atkDamage(0) {
	if (name.empty())
		throw std::invalid_argument("Name of a claptrap is empty!\n");
	std::cout << "ClapTrap String Constructor has been called\n";
	_name = name;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _hitPoints(10), _energyPoints(10), _atkDamage(0) {
	std::cout << "ClapTrap Copy Constructor has been called\n";
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (*this == other)
		return *this;
	std::cout << "Copy Assignment operator has been called\n";
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_atkDamage = other._atkDamage;
	return *this;
}

bool ClapTrap::operator==(const ClapTrap& other) {
	return this->_name == other._name && this->_hitPoints == other._hitPoints 
			&& this->_energyPoints == other._energyPoints && this->_atkDamage == other._atkDamage;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap is destroyed!\n";
}

void ClapTrap::status() {
	std::cout << "[HP: " << this->_hitPoints << "; EP: " << this->_energyPoints 
	<< "; ATK: " << this->_atkDamage << "]\n";
}

void ClapTrap::attack(const std::string& target) {
	if (!this->canAct()) {
		std::cout << "ClapTrap " << _name << " unable to act!";
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target 
				<< ", causing " << this->_atkDamage 
				<<  " points of damage!\n";
	this->_energyPoints--;
	status();
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " already broken!\n";
		return;
	}
	std::cout << "ClapTrap " << this->_name << " takes " 
				<< amount << " points of damage" 
				<< (this->_hitPoints > amount ? "!\n" : " and is broken!\n");
	int temp = _hitPoints;
	if (temp - amount < 0)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	status();
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->canAct()) {
		std::cout << "ClapTrap " << _name << " unable to act!\n";
		return;
	}
	long temp = _hitPoints;
	if (temp + amount > std::numeric_limits<unsigned int>::max())
		this->_hitPoints = std::numeric_limits<unsigned int>::max();
	else
		this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name 
				<< " is repaired for " << amount << "!\n";
	this->_energyPoints--;
	status();
}

bool ClapTrap::canAct() {
	return this->_energyPoints > 0 && this->_hitPoints > 0;
}

