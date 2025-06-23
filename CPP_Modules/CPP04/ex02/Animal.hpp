#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
protected:
	std::string _type;
	AAnimal();
	AAnimal(const AAnimal& other);
	virtual ~AAnimal();
	AAnimal& operator=(const AAnimal& other);
	
	virtual void makeSound() const = 0;
	void setType(const std::string& type);
	std::string getType() const;
};

#endif