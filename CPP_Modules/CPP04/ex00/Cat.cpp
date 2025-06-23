#include "Cat.hpp"

Cat::Cat() : Animal() {
	setType("Cat");
	std::cout << "Cat Constructor called!\n";
}

Cat::Cat(const Cat& other) : Animal() {
	setType(other._type);
	std::cout << "Cat Copy Constructor called!\n";
}

Cat& Cat::operator=(const Cat& other) {
	if (this == &other)
		return *this;
	setType(other._type);
	std::cout << "Cat Copy Assignment operator called!\n";
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called!\n";
}

void Cat::makeSound() const {
	std::cout << "MEOW MEOW\n";
}