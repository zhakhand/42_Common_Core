#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>

template <typename T, typename Function>
void iter(T* array, size_t len, Function function) {
	for(size_t i = 0; i < len; ++i) function(array[i]);
}

#endif