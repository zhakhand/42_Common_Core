#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <vector>
#include <iostream>

class Object {
public:
	int	_value;
	int	_depth;
	std::vector<int> _pairs;

	Object();
	Object(int value);
	Object(const Object& other);
	Object& operator=(const Object& other);
	~Object();
};

std::ostream& operator<<(std::ostream& o, const Object& obj);
bool operator>(const Object& lhs, const Object& rhs);

#endif