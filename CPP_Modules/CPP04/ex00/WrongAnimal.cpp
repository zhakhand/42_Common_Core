#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() :  _type("animal") {
	std::cout << "WrongAnimal Constructor called!\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
	std::cout << "WrongAnimal Copy Constructor called!\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this == &other)
		return *this;
	std::cout << "WrongAnimal Copy Assignment operator called!\n";
	this->_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called!\n";
}

void WrongAnimal::makeSound() const {
	std::cout << "I am animal, i guess...\n";
}

std::string WrongAnimal::getType() const {
	return this->_type;
}

void WrongAnimal::setType(const std::string& type) {
	this->_type = type;
}
