#include "PmergeMe.hpp"

const Vec PmergeMe::sortVec(int ac, char *av[]) {
	Vec input;
	input.reserve(ac - 1);
	checkInputVec(ac, av, input);
	dump<Vec, VecConstIt>(input);
	Vec sorted = mergeInsertionVec(input);
	dump<Vec, VecConstIt> (sorted);
	return sorted;
}

void PmergeMe::checkInputVec(int ac, char *av[], Vec& vec) {
	for (int i = 1; i < ac; ++i) {
		std::string arg(av[i]);
		if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
			throw std::invalid_argument("Invalid input => " + arg + "\n");
		int number = toInt(arg);
		vec.push_back(Object(number));
	}
}

int pairemUp(Vec& vec) {
	VecIt it = vec.begin();
	int index = 0;
	int counter = 0;
	while (it != vec.end()) {
		VecIt first = it++;
		if (it != vec.end()) {
			first->_pairs.push_back(index);
			first->_depth++;
			it->_pairs.push_back(index);
			it->_depth++;
			if (*first > *it) {
				std::swap(*first, *it);
			}
			counter++;
			index++;
		} else break;
	}
	return counter;
}

Vec collectSmalls(const Vec& vec) {
	Vec smalls;
	smalls.reserve(vec.size() / 2);
	for (int i = 0; i < (int)vec.size(); i += 2) {
		smalls.push_back(vec[i]);
	}
	return smalls;
}

Vec collectBigs(const Vec& vec) {
	Vec bigs;
	bigs.reserve(vec.size() / 2);
	for (int i = 1; i < (int)vec.size(); i += 2) {
		bigs.push_back(vec[i]);
	}
	return bigs;
}

void PmergeMe::binaryInsertVec(Vec& bigs, Object& obj, int dist) {
	VecIt low = bigs.begin();
	VecIt high = bigs.begin() + dist;

	while (low != high) {
		VecIt mid = low + (high - low) / 2;
		if (*mid > obj) high = mid;
		else low = mid + 1;
		counter++;
	}
	bigs.insert(low, obj);
}

void PmergeMe::insertSmallVec(Vec& bigs, Vec& smalls, Object& leftover) {
	std::vector<int> jacobsthal = generateJacobsthal(bigs.size());
	const Vec reference = bigs;
	int	currDepth = reference[0]._depth;
	for (size_t i = 0; i < jacobsthal.size(); ++i) {
		int index = jacobsthal[i] - 1;
		if (index < (int)reference.size()) {
			int pairIndex = *(reference[index]._pairs.begin() + currDepth);
			size_t pos;
			for (pos = 0; pos < bigs.size(); ++pos) {
				int check = bigs[pos]._depth;
				if (check == currDepth && bigs[pos]._pairs.empty() && bigs[pos]._pairs[bigs[pos]._depth] == pairIndex)
					break;
			}
			binaryInsertVec(bigs, smalls[pairIndex], pos);
		}
		if (index >= (int)reference.size() && leftover._value != -1)
			binaryInsertVec(bigs, leftover, bigs.size());
	}
	for (size_t i = 0; i < bigs.size(); ++i) {
		if (bigs[i]._depth == currDepth)
			bigs[i]._depth--;
	}
}

Vec PmergeMe::mergeInsertionVec(Vec& vec) {
	if (vec.size() <= 1)
		return vec;
	Object leftover(-1);
	if (vec.size() % 2 == 1) {
		leftover = vec.back();
		leftover._depth++;
		vec.pop_back();
	}
	counter += pairemUp(vec);
	Vec smalls = collectSmalls(vec);
	Vec bigs = collectBigs(vec);
	Vec sorted = mergeInsertionVec(bigs);
	//std::cout << leftover << "\n";
	insertSmallVec(sorted, smalls, leftover);
	// dump<Vec, VecConstIt>(smalls);
	// dump<Vec, VecConstIt>(bigs);
	return sorted;
}