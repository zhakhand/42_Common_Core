#include "Animal.hpp"

Animal::Animal() :  _type("animal") {
	std::cout << "Animal Constructor called!\n";
}

Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << "Animal Copy Constructor called!\n";
}

Animal& Animal::operator=(const Animal& other) {
	if (this == &other)
		return *this;
	std::cout << "Animal Copy Assignment operator called!\n";
	this->_type = other._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called!\n";
}

void Animal::makeSound() const {
	std::cout << "I am animal, i guess...\n";
}

std::string Animal::getType() const {
	return this->_type;
}

void Animal::setType(const std::string& type) {
	this->_type = type;
}
