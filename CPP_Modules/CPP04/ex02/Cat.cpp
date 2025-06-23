#include "Cat.hpp"

Cat::Cat() {
	setType("Cat");
	this->_brain = new Brain();
	std::cout << "Cat Constructor called!\n";
}

Cat::Cat(const Cat& other) {
	setType(other._type);
	this->_brain = new Brain(*other._brain);
	std::cout << "Cat Copy Constructor called!\n";
}

Cat& Cat::operator=(const Cat& other) {
	if (this == &other)
		return *this;
	setType(other._type);
	*this->_brain = *other._brain;
	std::cout << "Cat Copy Assignment operator called!\n";
	return *this;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat Destructor called!\n";
}

void Cat::makeSound() const {
	std::cout << "MEOW MEOW\n";
}

void Cat::insertIdea(const std::string& idea, size_t pos) {
	this->_brain->setIdea(idea, pos);
}

std::string Cat::getIdea(size_t pos) const {
	return this->_brain->getThought(pos);
}