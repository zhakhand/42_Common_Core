#pragma once
#ifndef __HUMANB_H__
#define __HUMANB_H__

#include "Weapon.hpp"

class HumanB {
private:
	std::string name;
	Weapon *weapon;
public:
	HumanB();
	HumanB(std::string nameIn);
	HumanB(std::string nameIn, Weapon &weaponIn);
	~HumanB();
	void setWeapon(Weapon &weaponIn);
	void attack();
};

#endif