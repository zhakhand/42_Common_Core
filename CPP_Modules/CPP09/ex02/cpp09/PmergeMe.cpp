#include "PmergeMe.hpp"
#include "object.hpp"

PmergeMe::PmergeMe() : counter(0){}

PmergeMe::PmergeMe(const PmergeMe& other){(void)other;}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {(void)other; return *this;}

PmergeMe::~PmergeMe() {}

int PmergeMe::toInt(const std::string& number) {
	int res = 0;
	for (size_t i = 0; i < number.length(); ++i) {
		res = res * 10 + (number[i] - '0');
		if (res < 0)
			throw std::runtime_error("Int Overflow => " + number + "\n");
	}
	return res;
}

std::vector<int> PmergeMe::generateJacobsthal(int size) {
	std::vector<int> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	int next = 0;
	while (next < size) {
		next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}
	std::vector<int> result;
	for (size_t i = 0; i < jacobsthal.size(); ++i) {
		if (i == 1 || i == 0) continue;
		if (jacobsthal[i] < size)
			result.push_back(jacobsthal[i]);

		/* Put Remaining Indexes */
		// 0* 1* 3* 2 5* 4 11* 10 9 8 7 6 *21 20 ...
		if (i > 2) {
			for (int j = jacobsthal[i] - 1; j > jacobsthal[i - 1]; --j)
				result.push_back(j);
		}
	}
	return result;
}