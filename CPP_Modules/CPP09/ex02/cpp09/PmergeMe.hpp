#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <ctime>
#include "object.hpp"

typedef std::vector<Object> Vec;
typedef Vec::iterator VecIt;
typedef Vec::const_iterator VecConstIt;

typedef std::deque<Object> Deq;
typedef Deq::iterator DeqIt;
typedef Deq::const_iterator DeqConstIt;

class PmergeMe {
private:
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
public:
	int counter;
	PmergeMe();
	~PmergeMe();
	int toInt(const std::string& number);
	std::vector<int> generateJacobsthal(int size);

	void checkInputVec(int ac, char *av[], Vec& vec);
	const Vec sortVec(int ac, char *av[]);
	Vec mergeInsertionVec(Vec& vec);
	void insertSmallVec(Vec& bigs, Vec& smalls, Object& leftover);
	void binaryInsertVec(Vec& bigs, Object& obj, int dist);

	void checkInputDeq(char *av[], Deq& deq);
	const Deq sortDeq(int ac, char *av[]);
	
	template <typename Container, typename iterator>
	void dump(const Container& container);
};

template <typename Container, typename iterator>
void PmergeMe::dump(const Container& container) {
	iterator start = container.begin();
	iterator end = container.end();
	while (start != end) {
		std::cout << *start << " ";
		start++;
	}
	std::cout << "\n";
}



#endif