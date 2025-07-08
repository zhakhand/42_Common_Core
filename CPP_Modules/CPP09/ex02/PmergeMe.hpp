#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <ctime>
#include "Object.hpp"

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

	void checkInputVec(int ac, char *av[], Vec& vec);
	const Vec sortVec(int ac, char *av[]);
	Vec mergeInsertionVec(Vec& vec);
	void insertSmallVec(Vec& bigs, Vec& smalls, Object& leftover);
	void findInsertVec(Vec& bigs, const Vec& smalls, int index);
	void binaryInsertVec(Vec& bigs, const Object& obj, int dist);

	void checkInputDeq(int ac, char *av[], Deq& deq);
	const Deq sortDeq(int ac, char *av[]);
	Deq mergeInsertionDeq(Deq& deq);
	void insertSmallDeq(Deq& bigs, Deq& smalls, Object& leftover);
	void findInsertDeq(Deq& bigs, const Deq& smalls, int index);
	void binaryInsertDeq(Deq& bigs, const Object& obj, int dist);

	template <typename Container, typename iterator>
	void dump(const Container& container);
};

template <typename Container, typename iterator>
void PmergeMe::dump(const Container& container) {
	iterator start = container.begin();
	iterator end = container.end();
	short count = 0;
	while (start != end) {
		if (count == 20) {
			std::cout << "[...]";
			break;
		}
		std::cout << *start << " ";
		start++;
		count++;
	}
	std::cout << "\n";
}



#endif