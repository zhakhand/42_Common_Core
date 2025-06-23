#pragma once
#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
protected:
	static const unsigned int _hitPoints = 100;
	static const unsigned int _energyPoints = 50;
	static const unsigned int _atkDamage = 20;
public:
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();
	
	void attack(const std::string& target);
	void guardGate();
};

#endif