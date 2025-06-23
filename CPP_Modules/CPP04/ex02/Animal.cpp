#include "Animal.hpp"

AAnimal::AAnimal() :  _type("animal") {
	std::cout << "AAnimal Constructor called!\n";
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
	std::cout << "AAnimal Copy Constructor called!\n";
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if (this == &other)
		return *this;
	std::cout << "AAnimal Copy Assignment operator called!\n";
	this->_type = other._type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal Destructor called!\n";
}

void AAnimal::makeSound() const {
	std::cout << "I am animal, i guess...\n";
}

std::string AAnimal::getType() const {
	return this->_type;
}

void AAnimal::setType(const std::string& type) {
	this->_type = type;
}
