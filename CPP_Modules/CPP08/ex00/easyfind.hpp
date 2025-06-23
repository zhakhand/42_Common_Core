#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int target) {
	typename T::iterator iter = std::find(container.begin(), container.end(), target);
	if (iter != container.end()) return iter;
	throw std::invalid_argument("Target is not found!\n");
}

#endif