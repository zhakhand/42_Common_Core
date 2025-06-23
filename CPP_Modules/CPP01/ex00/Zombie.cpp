#include "Zombie.hpp"

Zombie::Zombie(std::string nameIn) {
	if (nameIn.empty())
		throw std::invalid_argument("Empty argument!");
	name = nameIn;
}

Zombie::~Zombie() {
	std::cout << this->name << " got shot...\n";
}

void Zombie::announce ( void ) {
	std::cout << (this->name == "Foo" ? this->name : ("<"+this->name+">"))
				<< ": BraiiiiiiinnnzzzZ...\n";
}