#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
	int _id;
	std::string _firstName;
	
	Data(int id, const std::string& name) : _id(id), _firstName(name) {}
};

#endif