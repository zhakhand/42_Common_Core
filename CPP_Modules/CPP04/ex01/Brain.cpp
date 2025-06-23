#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain is created!\n";
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain is copied!\n";
}

Brain& Brain::operator=(const Brain& other) {
	if (this == &other)
		return *this;
	
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain is copied!\n";
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain is deleted!\n";
}

void Brain::setIdea(const std::string& idea, size_t pos) {
	if (pos < 100)
		this->_ideas[pos] = idea;
}

std::string Brain::getThought(size_t pos) {
	return this->_ideas[pos];
}