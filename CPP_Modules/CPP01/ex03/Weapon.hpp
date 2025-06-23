#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>
#include <string>

class Weapon {
private:
	std::string type;
public:
	Weapon();
	Weapon(std::string typeIn);
	~Weapon();
	std::string getType() const;
	void setType(const std::string &typeIn);
};

#endif