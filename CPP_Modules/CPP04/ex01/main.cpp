#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		Animal **animals = new Animal*[20];
		for (int i = 0; i < 20; ++i) {
			if (i % 2) {
				animals[i] = new Dog();
				for (int k = 0; k < 100; ++k)
				((Dog*)(animals[i]))->insertIdea("I am a Dog", k);
			}
			else{
				animals[i] = new Cat();
				for (int j = 0; j < 100; ++j)
					((Cat*)(animals[i]))->insertIdea("I am a Cat", j);
			}
		}
		((Cat*)animals[0])->insertIdea("MEOW", 0);
		std::cout << ((Cat*)(animals[0]))->getIdea(0) << "\n";
		*(Cat*)animals[0] = *(Cat*)animals[2];
		std::cout << ((Cat*)(animals[0]))->getIdea(0) << "\n";
		std::cout << ((Dog*)(animals[1]))->getIdea(0) << "\n";

		for (int i = 0; i < 20; ++i) {
			delete animals[i];
		}
		delete[] animals;
	}
	Dog basic;
	{
		Dog tmp = basic;
	}
	Cat basic2;
	{
		Cat tmp = basic2;
	}
	return 0;
}