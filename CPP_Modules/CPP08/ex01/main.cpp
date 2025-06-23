#include "Span.hpp"
#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));
	{
		std::cout << "\n***** Exceptions *****\n";
		try {
			std::cout << "\n***** Should not fit simple *****\n";
			Span sp1 = Span(3);
			sp1.addNumber(1);
			sp1.addNumber(2);
			sp1.addNumber(3);
			sp1.addNumber(4);
		} catch (const std::exception& e) {
			std::cout << "Should throw: " << e.what();
		}
		try {
			std::cout << "\n***** Should not fit ranges *****\n";
			std::list<int> numbers;
			for (int i = 0; i < 30; ++i) numbers.push_back(rand());
			Span sp2 = Span(25);
			sp2.addNumbersFromSource(numbers);
		} catch (const std::exception& e) {
			std::cout << "Should throw: " << e.what();
		}
		try {
			std::cout << "\n***** Should throw short *****\n";
			Span sp2 = Span(3);
			sp2.addNumber(1);
			std::cout << "Shortest span: " << sp2.shortestSpan() << "\n";
		} catch (const std::exception& e) {
			std::cout << "Should throw: " << e.what();
		}
		try {
			std::cout << "\n***** Should throw short *****\n";
			Span sp3 = Span(3);
			sp3.addNumber(1);
			std::cout << "Longest span: " << sp3.longestSpan() << "\n";
		} catch (const std::exception& e) {
			std::cout << "Should throw: " << e.what();
		}
	}
	{
		std::cout << "\n***** Simple tests *****\n";
		try {
			std::cout << "\n***** Short Simple Add *****\n";
			Span sp1 = Span(5);
			sp1.addNumber(1);
			sp1.addNumber(4);
			sp1.addNumber(3);
			sp1.addNumber(7);
			sp1.addNumber(12);
			std::cout << "Shortest span: " << sp1.shortestSpan() << "\n";
			std::cout << "Longestest span: " << sp1.longestSpan() << "\n";
			std::cout << "Size: " << sp1.getSize() << "\n";
		} catch (const std::exception& e) {
			std::cout << "Thrown: " << e.what();
		}
		try {
			std::cout << "\n***** Short Ranges Add *****\n";
			std::list<int> numbers;
			for (int i = 0; i < 100; ++i) numbers.push_back(rand());
			Span sp2 = Span(100);
			sp2.addNumbersFromSource(numbers);
			std::cout << "Shortest span: " << sp2.shortestSpan() << "\n";
			std::cout << "Longest span: " << sp2.longestSpan() << "\n";
			std::cout << "Size: " << sp2.getSize() << "\n";
		} catch (const std::exception& e) {
			std::cout << "Thrown: " << e.what();
		}
	}
	{
		std::cout << "\n***** 10000 numbers tests *****\n";
		try {
			std::cout << "\n***** Simple Add *****\n";
			Span sp1 = Span(10000);
			for (int i = 0; i < 10000; ++i) sp1.addNumber(rand());
			std::cout << "Shortest span: " << sp1.shortestSpan() << "\n";
			std::cout << "Longestest span: " << sp1.longestSpan() << "\n";
			std::cout << "Size: " << sp1.getSize() << "\n";
		} catch (const std::exception& e) {
			std::cout << "Thrown: " << e.what();
		}
		try {
			std::cout << "\n***** Ranges Add *****\n";
			std::list<int> numbers;
			for (int i = 0; i < 10000; ++i) numbers.push_back(rand());
			Span sp2 = Span(10000);
			sp2.addNumbersFromSource(numbers);
			std::cout << "Shortest span: " << sp2.shortestSpan() << "\n";
			std::cout << "Longest span: " << sp2.longestSpan() << "\n";
			std::cout << "Size: " << sp2.getSize() << "\n";
		} catch (const std::exception& e) {
			std::cout << "Thrown: " << e.what();
		}
	}
}