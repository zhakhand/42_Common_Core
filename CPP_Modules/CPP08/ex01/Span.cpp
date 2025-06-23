#include "Span.hpp"

Span::Span() : _vals(std::vector<int>(0)), _N(0), _size(0) {}

Span::Span(unsigned int N) : _vals(std::vector<int>()), _N(N), _size(0) {_vals.reserve(_N);}

Span::Span(const Span& other) : _N(other._N), _size(other._size) {
	this->_vals = other._vals;
}

Span& Span::operator=(const Span& other) {
	if (this == &other) return *this;
	this->_vals = other._vals;
	this->_N = other._N;
	this->_size = other._size;
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (_size == _N) throw std::runtime_error("Span is already full!\n");
	this->_vals.push_back(number);
	this->_size++;
}

size_t Span::getSize() const {
	return this->_vals.size();
}

unsigned int Span::shortestSpan() {
	if (_size <= 1) throw std::runtime_error("Span is too short!\n");
	std::vector<int> sortedVals = this->_vals;
	std::sort(sortedVals.begin(), sortedVals.end());
	MinSpanAccumulator minAcc;
	minAcc = std::for_each(sortedVals.begin(), sortedVals.end(), minAcc);
	return minAcc.getMinSpan();
}

unsigned int Span::longestSpan() {
	if (_size <= 1) throw std::runtime_error("Span is too short!\n");
	return static_cast<unsigned int>
			(*std::max_element(this->_vals.begin(), this->_vals.end()) 
			- *std::min_element(this->_vals.begin(), this->_vals.end()));
}

MinSpanAccumulator::MinSpanAccumulator() : minSpan(std::numeric_limits<unsigned int>::max()), lastVal(0), first(true) {}

MinSpanAccumulator::MinSpanAccumulator(const MinSpanAccumulator& other) : minSpan(other.getMinSpan()) {}

MinSpanAccumulator& MinSpanAccumulator::operator=(const MinSpanAccumulator& other) {
	if (this == &other) return *this;
	this->minSpan = other.getMinSpan();
	this->lastVal = other.lastVal;
    this->first = other.first;
	return *this;
}

MinSpanAccumulator::~MinSpanAccumulator() {}

void MinSpanAccumulator::operator()(int value) {
	if (!first) {
		unsigned int span = static_cast<unsigned int>(value - lastVal);
		if (span < minSpan)
			minSpan = span;
	} else {
		first = false;
	}
	lastVal = value;
}

unsigned int MinSpanAccumulator::getMinSpan() const {return minSpan;}

