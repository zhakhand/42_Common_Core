#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	FragTrap a = FragTrap("Bob");
	FragTrap b = FragTrap("John");
	ClapTrap *c = &a;
	c->attack("something");
	a.beRepaired(42);
	a.takeDamage(120);
	a.attack("bunny");
	a.highFivesGuys();
	b.takeDamage(99);
	b.attack("mi spogetti");
	b.highFivesGuys();
	b = a;
	b.attack("nothing");
	return 0;
}