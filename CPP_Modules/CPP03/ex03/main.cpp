#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap a = DiamondTrap("Bob");
	DiamondTrap b = DiamondTrap("John");
	ClapTrap *c = &a;
	c->attack("something");
	a.beRepaired(42);
	a.takeDamage(120);
	a.attack("bunny");
	a.highFivesGuys();
	b.takeDamage(99);
	b.attack("mi spogetti");
	b.highFivesGuys();
	b.whoAmI();
	b = a;
	b.attack("nothing");
	b.whoAmI();
	return 0;
}