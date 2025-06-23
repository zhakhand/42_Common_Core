#pragma once
#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
	ScavTrap();
public:
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	bool operator==(const ScavTrap& other);
	~ScavTrap();
	
	void attack(const std::string& target);
	void guardGate();
};

#endif