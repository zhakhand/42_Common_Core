#pragma once
#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <iostream>
#include <string>
#include <limits>

class ClapTrap {
private:
	std::string _name;
	unsigned int	_hitPoints;
	unsigned int _energyPoints;
	unsigned int _atkDamage;
public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	bool operator==(const ClapTrap& other);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void status();
	bool canAct();
};


#endif