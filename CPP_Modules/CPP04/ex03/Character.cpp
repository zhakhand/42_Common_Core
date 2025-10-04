#include "Character.hpp"
#include <iostream>

Character::Character() : _name("Default") {
    for (size_t i = 0; i < 4; ++i) _inventory[i] = NULL;
}

Character::Character(const std::string& name) : _name(name) {
    for (size_t i = 0; i < 4; ++i) _inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name) {
    for (size_t i = 0; i < 4; ++i) {
        if (other._inventory[i]) _inventory[i] = other._inventory[i]->clone();
        else _inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        _name = other._name;
        for (size_t i = 0; i < 4; ++i) {
            if (_inventory[i]) delete _inventory[i];
            if (other._inventory[i]) _inventory[i] = other._inventory[i]->clone();
            else _inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    for (size_t i = 0; i < 4; ++i) {
        if (_inventory[i]) {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m) return;
    for (size_t i = 0; i < 4; ++i) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            return;
        }
    }
    std::cout << "Inventory full!\n";
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid index!\n";
        return;
    }
    if (_inventory[idx]) _inventory[idx] = NULL;
    else std::cout << "No materia at index " << idx << "!\n";
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid index!\n";
        return;
    }
    if (_inventory[idx]) _inventory[idx]->use(target);
    else std::cout << "No materia at index " << idx << "!\n";
}