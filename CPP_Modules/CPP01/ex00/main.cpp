#include "Zombie.hpp"

int main( void ) {
	try {
		Zombie *zombie1 = newZombie("Foo");
		zombie1->announce();
		delete zombie1;
		Zombie *zombie2 = newZombie("Allen");
		zombie2->announce();
		delete zombie2;
		Zombie *zombie3 = newZombie("Barry");
		zombie3->announce();
		delete zombie3;

		randomChump("Foo");
		randomChump("Fighters");
		randomChump("Everlong");
		Zombie *zombie4 = newZombie("");
		zombie4->announce();
		delete zombie4;
		randomChump("");
	} catch (const std::invalid_argument &e){
		std::cerr << e.what() << "\n";
	}
}