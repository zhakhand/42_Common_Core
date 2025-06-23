#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	setType("WrongCat");
	std::cout << "WrongCat Constructor called!\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal() {
	setType(other._type);
	std::cout << "WrongCat Copy Constructor called!\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this == &other)
		return *this;
	setType(other._type);
	std::cout << "WrongCat Copy Assignment operator called!\n";
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called!\n";
}

void WrongCat::makeSound() const {
	std::cout << "MEOW MEOW\n";
}