#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
private:
	Brain *_brain;
public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	virtual ~Dog();

	void makeSound() const;
	void insertIdea(const std::string& idea, size_t pos);
	std::string getIdea(size_t pos) const;
};

#endif