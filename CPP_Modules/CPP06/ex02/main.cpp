#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <exception>

Base* generate() {
	int chance = std::rand() % 3;
	switch (chance) {
		case 0:
			std::cout << "Generated A\n";
			return new A();
		case 1:
			std::cout << "Generated B\n";
			return new B();
		default:
			std::cout << "Generated C\n";
			return new C();
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) std::cout << "That's pointer to 'A'!\n";
	else if (dynamic_cast<B*>(p)) std::cout << "That's pointer to 'B'!\n";
	else if (dynamic_cast<C*>(p)) std::cout << "That's pointer 'C'!\n";
	else std::cout << "IDEK!\n";
}

void identify(Base& p) {
	try {
		A& aRef = dynamic_cast<A&>(p);
		(void)aRef;
		std::cout << "That's reference to A!\n";
		return;
	} catch(...) {}
	try {
		B& bRef = dynamic_cast<B&>(p);
		(void)bRef;
		std::cout << "That's reference to B!\n";
		return;
	} catch(...) {}
	try {
		C& cRef = dynamic_cast<C&>(p);
		(void)cRef;
		std::cout << "That's reference to C!\n";
		return;
	} catch(...) {}
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));
	for (int i = 0; i < 10; ++i) {
		std::cout << "\n****** Test No" << i + 1 << " ******\n";
		Base* smth = generate();
		identify(smth);
		identify(*smth);
		delete smth;
	}
}