#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	~WrongAnimal();
	WrongAnimal& operator=(const WrongAnimal& other);
	
	void makeSound() const;
	void setType(const std::string& type);
	std::string getType() const;
};

#endif