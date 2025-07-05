#include "object.hpp"

Object::Object() {}

Object::Object(int value) : _value(value), _depth(-1), jacobsthalNumber(-1), isLeftover(false) {}

Object::Object(const Object& other) {
	this->_value = other._value;
	this->jacobsthalNumber = other.jacobsthalNumber;
	this->_depth = other._depth;
	this->isLeftover = other.isLeftover;
	this->pairs = other.pairs;
}

Object& Object::operator=(const Object& other) {
	if (this == &other) return *this;
	this->_value = other._value;
	this->jacobsthalNumber = other.jacobsthalNumber;
	this->_depth = other._depth;
	this->isLeftover = other.isLeftover;
	this->pairs = other.pairs;
	return *this;
}

Object::~Object() {}

std::ostream& operator<<(std::ostream& o, const Object& obj) {
	o << obj._value;
	return o;
}

bool operator>(const Object& lhs, const Object& rhs) {
	return lhs._value > rhs._value;
}

bool operator<(const Object& lhs, const Object& rhs) {
	return lhs._value < rhs._value;
}


