#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (size_t i = 0; i < 4; ++i) _materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (size_t i = 0; i < 4; ++i) {
        if (other._materias[i]) _materias[i] = other._materias[i]->clone();
        else _materias[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (size_t i = 0; i < 4; ++i) {
            if (_materias[i]) delete _materias[i];
            if (other._materias[i]) _materias[i] = other._materias[i]->clone();
            else _materias[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (size_t i = 0; i < 4; ++i) {
        if (_materias[i]) {
            delete _materias[i];
            _materias[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (size_t i = 0; i < 4; ++i) {
        if (!_materias[i]) {
            _materias[i] = m;
            return;
        }
    }
    std::cout << "Materia source full!\n";
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (size_t i = 0; i < 4; ++i) {
        if (_materias[i] && _materias[i]->getType() == type) {
            return _materias[i]->clone();
        }
    }
    std::cout << "Unknown materia type: " << type << "\n";
    return NULL;
}