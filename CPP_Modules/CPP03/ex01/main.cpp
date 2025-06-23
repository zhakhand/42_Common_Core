#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ScavTrap a = ScavTrap("Bob");
	ScavTrap b = ScavTrap("John");
	ClapTrap *c = &a;
	c->attack("something");
	a.beRepaired(42);
	a.takeDamage(120);
	a.attack("bunny");
	a.guardGate();
	b.takeDamage(99);
	b.attack("mi spogetti");
	b.guardGate();
	b = a;
	b.attack("nothing");
	b.guardGate();
	return 0;
}