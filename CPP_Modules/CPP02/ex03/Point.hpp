#pragma once
#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
#include "Fixed.hpp"

class Point {
private:
	Fixed const _x;
	Fixed const _y;

public:
	Point();
	Point(const float& x, const float& y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();
	std::pair<float, float> getPoint() const;
};

#endif