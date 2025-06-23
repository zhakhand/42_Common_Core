#include "Dog.hpp"

Dog::Dog() {
	setType("Dog");
	std::cout << "Dog Constructor called!\n";
}

Dog::Dog(const Dog& other) {
	setType(other._type);
	std::cout << "Dog Copy Constructor called!\n";
}

Dog& Dog::operator=(const Dog& other) {
	if (this == &other)
		return *this;
	setType(other._type);
	std::cout << "Dog Copy Assignment operator called!\n";
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called!\n";
}

void Dog::makeSound() const {
	std::cout << "WOOF WOOF\n";
}