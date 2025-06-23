#include "Harl.hpp"

int main(int ac, char *av[]) {
	Harl haarl;
	if (ac != 2)
		return haarl.complain("nothing"), 0;
	std::string str(av[1]);
	haarl.complain(str);
	return 0;
}