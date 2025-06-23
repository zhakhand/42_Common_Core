#include "ClapTrap.hpp"

int main(void) {
	ClapTrap a = ClapTrap("GigaChad");

	for(int i = 0; i < 8; i++) a.attack("mi spaghetti");
	for(int i = 0; i < 3; i++) a.takeDamage(3);
	for(int i = 0; i < 3; i++) a.beRepaired(3);
	return 0;
}