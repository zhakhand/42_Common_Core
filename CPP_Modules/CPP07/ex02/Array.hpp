#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stdexcept>

template <typename T>
class Array {
private:
	unsigned int _size;
	T* _vals;
public:
	Array() : _size(0), _vals(NULL) {}
	
	Array(unsigned int n) : _size(n), _vals(new T[n]()) {}
	
	Array(const Array<T>& other) : _size(other._size) {
		this->_vals =  new T[_size]();
		for (unsigned int i = 0; i < _size; ++i)
			this->_vals[i] = other._vals[i];
	}

	Array& operator=(const Array<T>& other) {
		if (this == &other) return *this;
		delete[] this->_vals;
		this->_size = other._size;
		this->_vals = new T[_size]();
		for (unsigned int i = 0; i < _size; ++i)
			this->_vals[i] = other._vals[i];
		return *this;
	}

	~Array() {delete[] _vals;}

	unsigned int size() const {
		return this->_size;
	}

	T& operator[](size_t index) {
		if (index >= (size_t)this->_size)
			throw std::invalid_argument("Given index is out of bounds!");
		return this->_vals[index];
	}

	const T& operator[](size_t index) const {
		if (index >= (size_t)this->_size)
			throw std::invalid_argument("Given index is out of bounds!");
		return this->_vals[index];
	}
};

#endif