#include "ScalarConverter.hpp"

int main(int ac, char *av[]) {
	if (ac != 2) {
		std::cerr << "Provide an argument!\n";
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}