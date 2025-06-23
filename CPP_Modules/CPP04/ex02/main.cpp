#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Dog dog = Dog();
	Cat cat = Cat();

	AAnimal *animal = new Dog();
	animal->makeSound();
	delete animal;
	return 0;
}