#include <iostream>
#include "iter.hpp"

template <typename T>
void toPrint(const T& val) {
	std::cout << val << "\n";
}

template <typename T>
void modulo2(const T& val) {
	std::cout << val % 2 << "\n";
}

int main() {
	int array[] = {24, 45, 42, 23, 33};
	size_t len = sizeof(array)/sizeof(array[0]);
	iter(array, len, toPrint<int>);
	iter(array, len, modulo2<int>);

	char charArray[] = {'H', 'E', 'L', 'L', 'O'};
	len = sizeof(charArray)/sizeof(charArray[0]);
	iter(charArray, len, toPrint<char>);
	iter(charArray, len, modulo2<char>);
}