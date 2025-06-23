#include "Point.hpp"

Point::Point() : _x(0), _y(0){}

Point::Point(const float& x, const float& y) : _x(Fixed(x)), _y(Fixed(y)){}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point& other) {
	(void) other;
	return *this;
}

Point::~Point() {}

std::pair<float, float> Point::getPoint() const {
	return std::make_pair(this->_x.toFloat(), this->_y.toFloat());
}
