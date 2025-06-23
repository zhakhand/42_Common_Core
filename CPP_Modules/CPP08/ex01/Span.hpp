#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <vector>

class Span {
private:
	std::vector<int> _vals;
	unsigned int _N;
	unsigned int _size;
public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();
	
	void addNumber(int number);
	size_t getSize() const;
	unsigned int shortestSpan();
	unsigned int longestSpan();

	template <typename T>
	void addNumbersFromSource(const T& source) {
		unsigned int distance = std::distance(source.begin(), source.end());
		if (this->_size + distance >  this->_N)
			throw std::runtime_error("Range does not fit in Span\n");
		this->_size += distance;
		this->_vals.insert(this->_vals.end(), source.begin(), source.end());
	}
};

#include <limits>
#include <functional>

class MinSpanAccumulator {
private:
	unsigned int minSpan;
	int	lastVal;
	bool first;
public:
	MinSpanAccumulator();
	MinSpanAccumulator(const MinSpanAccumulator& other);
	MinSpanAccumulator& operator=(const MinSpanAccumulator& other);
	~MinSpanAccumulator();
	void operator()(int value);
	unsigned int getMinSpan() const;
};

#endif