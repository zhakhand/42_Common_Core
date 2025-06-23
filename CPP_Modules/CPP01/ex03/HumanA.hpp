#pragma once
#ifndef __HUMANA_H__
#define __HUMANA_H__

#include "Weapon.hpp"

class HumanA {
private:
	std::string name;
	Weapon *weapon;
public:
	HumanA();
	HumanA(std::string nameIn, Weapon &weaponIn);
	~HumanA();
	void attack();
};

#endif