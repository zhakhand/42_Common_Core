#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <string>
#include <iostream>

class Zombie {
private:
	std::string name;
public:
	Zombie();
	Zombie(std::string nameIn);
	~Zombie();
	void announce( void );
};

Zombie *zombieHorde( int N, std::string name );

#endif