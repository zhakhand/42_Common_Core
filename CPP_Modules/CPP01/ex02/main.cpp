#include <iostream>
#include <string>

int main( void ) {
	std::string hi = "HI THIS IS BRAIN";
	std::string* stringPTR = &hi;
	std::string& stringREF = hi;
	std::cout << "Mem Address of the string variable: " << &hi << "\n";
	std::cout << "Mem Address held by stringPTR: " << stringPTR << "\n";
	std::cout << "Mem Address held by stringREF: " << &stringREF << "\n";
	std::cout << "Value of string variable: " << hi << "\n";
	std::cout << "Value pointed by stringPTR: " << *stringPTR << "\n";
	std::cout << "Value pointed by stringREF: " << stringREF << "\n";
}