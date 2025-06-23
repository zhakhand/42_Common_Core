#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	const WrongAnimal* beta = new WrongAnimal();
	const Animal* k = new Dog();
	const WrongAnimal* l = new WrongCat();
	std::cout << l->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	l->makeSound(); //should display wrong sound
	beta->makeSound();
	delete meta;
	delete j;
	delete i;
	delete beta;
	delete k;
	delete l;
	return 0;
}