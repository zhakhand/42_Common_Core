#include "Zombie.hpp"

int main( void ) {
	try {
		Zombie *zombies = zombieHorde( 8, "Foo" );
		for (size_t i = 0; i < 8; ++i){zombies[i].announce();}
		delete[] zombies;
		Zombie *zombies1 = zombieHorde( 8, "Boo" );
		for (size_t i = 0; i < 8; ++i){zombies1[i].announce();}
		delete[] zombies1;
		Zombie *zombies2 = zombieHorde( 8, "" );
		for (size_t i = 0; i < 8; ++i){zombies2[i].announce();}
		delete[] zombies2;
	} catch (const std::invalid_argument &e){
		std::cerr << e.what();
	}
}