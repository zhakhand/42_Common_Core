#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name){
	Zombie *zombies = new Zombie[N];
	try {
		for (int i = 0; i < N; ++i){new (&zombies[i]) Zombie(name);}
	} catch (const std::logic_error &e){
		delete[] zombies;
		std::cerr << e.what() << "\n";
		throw std::invalid_argument("");
	}
	return zombies;
}