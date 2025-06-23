#pragma once
#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
protected:
	static const unsigned int _hitPoints = 100;
	static const unsigned int _energyPoints = 100;
	static const unsigned int _atkDamage = 30;
public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap();

	void highFivesGuys(void);
};


#endif