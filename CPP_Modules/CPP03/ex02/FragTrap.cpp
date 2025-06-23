#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "FragTrap Constructor has been called!\n";
	_hitPoints = 100;
	_energyPoints = 100;
	_atkDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other._name) {
	if (*this == other)
		return;
	std::cout << "FragTrap Copy Constructor has been called!\n";
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (*this == other)
		return *this;
	std::cout << "FragTrap Copy Assignment operator has been called!\n";
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_atkDamage = other._atkDamage;
	return *this;
}

bool FragTrap::operator==(const FragTrap& other) {
	return _name == other._name && _hitPoints == other._hitPoints 
			&& _energyPoints == other._energyPoints && _atkDamage == other._atkDamage;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " is destroyed!\n";
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << " wants a high five!\n";
	while (!false) {
		try {
			std::string option;
			std::cout << "High Five?(yes/no): ";
			if (!std::getline(std::cin, option))
				throw std::logic_error("I didn't want to touch your hand anyway! T_T\n");
			if (option.empty())
				throw std::invalid_argument("Please answer yes or no!\n");
			if (option == "yes") {
				std::cout << _name << " is happy after a high five!\n";
				break;
			}
			else if (option == "no") {
				std::cout << _name << " is sad after being left hanging D:\n";
				break;
			}
			else
				throw std::invalid_argument("Say yes or no, please!\n");
		} catch (const std::invalid_argument &e) {
			std::cerr << e.what();
			continue;
		} catch (const std::logic_error &e) {
			std::cerr << e.what();
			std::cin.clear();
			return;
		}
	}
}