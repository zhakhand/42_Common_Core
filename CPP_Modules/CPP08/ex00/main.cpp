#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include "easyfind.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(static_cast<int>(std::time(0)));
	{
		try {
			std::cout << "\n***** Vector test *****\n";
			std::vector<int> nums;
			for (int i = 0; i < 100; ++i) nums.push_back(std::rand() % 100);
			std::vector<int>::iterator it = easyfind(nums, 42);
			int index = it - nums.begin();
			std::cout << "Number found: " << *it << " at index " << index << "\n";
		} catch (const std::exception& e) {
			std::cout << e.what();
		}
	}
	{
		try {
			std::cout << "\n***** Deque test *****\n";
			std::deque<int> nums;
			for (int i = 0; i < 100; ++i) nums.push_back(std::rand() % 100);
			std::deque<int>::iterator it = easyfind(nums, 42);
			int index = std::distance(nums.begin(), it);
			std::cout << "Number found: " << *it << " at index " << index << "\n";
		} catch (const std::exception& e) {
			std::cout << e.what();
		}
	}
	{
		try {
			std::cout << "\n***** Set test *****\n";
			std::set<int> nums;
			for (int i = 0; i < 100; ++i) nums.insert(std::rand() % 100);
			std::set<int>::iterator it = easyfind(nums, 42);
			int index = std::distance(nums.begin(), it);
			std::cout << "Number found: " << *it << " at index " << index << "\n";
		} catch (const std::exception& e) {
			std::cout << e.what();
		}
	}
}