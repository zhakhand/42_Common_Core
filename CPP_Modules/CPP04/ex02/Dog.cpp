#include "Dog.hpp"

Dog::Dog() {
	setType("Dog");
	std::cout << "Dog Constructor called!\n";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& other) {
	setType(other._type);
	this->_brain = new Brain(*other._brain);
	std::cout << "Dog Copy Constructor called!\n";
}

Dog& Dog::operator=(const Dog& other) {
	if (this == &other)
		return *this;
	setType(other._type);
	*this->_brain = *other._brain;
	std::cout << "Dog Copy Assignment operator called!\n";
	return *this;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog Destructor called!\n";
}

void Dog::makeSound() const {
	std::cout << "WOOF WOOF\n";
}

void Dog::insertIdea(const std::string& idea, size_t pos) {
	this->_brain->setIdea(idea, pos);
}

std::string Dog::getIdea(size_t pos) const {
	return this->_brain->getThought(pos);
}