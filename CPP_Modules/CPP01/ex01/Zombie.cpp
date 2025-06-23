#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(std::string nameIn) {
	if (nameIn.empty())
	{
		throw std::logic_error("Empty argument!");
		return ;
	}
	name = nameIn;
}

Zombie::~Zombie() {
	if (!this->name.empty())
		std::cout << this->name << " got shot...\n";
}

void Zombie::announce ( void ) {
	std::cout << (this->name == "Foo" ? this->name : ("<"+this->name+">"))
				<< ": BraiiiiiiinnnzzzZ...\n";
}