#include "PmergeMe.hpp"

const Vec PmergeMe::sortVec(int ac, char *av[]) {
	Vec input;
	input.reserve(ac - 1);
	checkInputVec(ac, av, input);
	std::cout << "\nBefore: ";
	dump<Vec, VecConstIt>(input);
	std::clock_t start = std::clock();
	Vec sorted = mergeInsertionVec(input);
	std::clock_t end = std::clock();
	std::cout << "\nAfter: ";
	dump<Vec, VecConstIt> (sorted);
	std::cout << "\nTime to process the range of " 
				<< input.size() << " with std::vector : " 
				<< static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0 << " microsecs\n";
	std::cout << "Number of comparisons: " << counter << "\n";
	return sorted;
}

void PmergeMe::checkInputVec(int ac, char *av[], Vec& vec) {
	for (int i = 1; i < ac; ++i) {
		const std::string arg(av[i]);
		if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
			throw std::invalid_argument("Invalid input => " + arg + "\n");
		int number = toInt(arg);
		vec.push_back(Object(number));
	}
}

static std::vector<int> fillSequence(const std::vector<int>& jacobsthal, int size) {
	std::vector<int> result;
	for (size_t i = 0; i < jacobsthal.size(); ++i) {
        int start = jacobsthal[i];
        int end = 0;
        if (i != 0)
            end = jacobsthal[i - 1];
        for (int num = start; num > end; --num)
            result.push_back(num);
    }
	if (jacobsthal.back() < size) {
		for (int i = size - 1; i > jacobsthal.back(); --i) result.push_back(i);
	}
	for (size_t i = 0; i < result.size(); ++i) 
        result[i] = result[i] - 1;
	return result;
}

static std::vector<int> generateJacobsthal(int size) {
    if (size <= 0) return std::vector<int>();
    
	std::vector<int> jacobsthal;
    jacobsthal.reserve(20);
    jacobsthal.push_back(0);

    if (size > 1) jacobsthal.push_back(1);
    
	while (true) {
        int next = jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next >= size) break;
        jacobsthal.push_back(next);
    }
    if (jacobsthal.size() > 2)
        jacobsthal.erase(jacobsthal.begin(), jacobsthal.begin() + 2);
    return fillSequence(jacobsthal, size);
}

int pairemUp(Vec& vec) {
	int index = 0;
	int counter = 0;
	for (size_t i = 0; i < vec.size(); i += 2) {
		if (vec[i] > vec[i + 1]) {
			std::swap(vec[i], vec[i + 1]);
		}
		counter++;
		vec[i].pairs.push_back(index);
		vec[i + 1].pairs.push_back(index);
		vec[i].jacobsthalNumber = -1;
		vec[i + 1].jacobsthalNumber = -1;
		index++;
	}
	return counter;
}

Vec collectSmalls(const Vec& vec) {
	Vec smalls;
	smalls.reserve(vec.size() / 2);
	for (size_t i = 0; i < vec.size(); i += 2) {
		smalls.push_back(vec[i]);
	}
	return smalls;
}

Vec collectBigs(const Vec& vec) {
	Vec bigs;
	bigs.reserve(vec.size() / 2);
	for (size_t i = 1; i < vec.size(); i += 2) {
		bigs.push_back(vec[i]);
	}
	return bigs;
}

void PmergeMe::binaryInsertVec(Vec& bigs, const Object& obj, int dist) {
	VecIt low = bigs.begin();
	VecIt high = bigs.begin() + dist;

	while (low != high) {
		VecIt mid = low + std::distance(low, high) / 2;
		if (*mid > obj) high = mid;
		else low = mid + 1;
		counter++;
	}
	bigs.insert(low, obj);
}

void PmergeMe::findInsertVec(Vec& bigs, const Vec& smalls, int index) {
    size_t bigPos = 0;
    const size_t bigsSize = bigs.size();
    while (bigPos < bigsSize && bigs[bigPos].jacobsthalNumber != index) 
		++bigPos;
    
    if (bigPos >= bigsSize) throw std::runtime_error("WHERE IS THE NUMBER?!\n");

    const int pairIndex = bigs[bigPos].pairs.back();
    const size_t smallsSize = smalls.size();
    for (size_t j = 0; j < smallsSize; ++j) {
        const Object& small = smalls[j];
        if (!small.pairs.empty() && small.pairs.back() == pairIndex) {
            binaryInsertVec(bigs, small, bigPos);
            return;
        }
    }
    throw std::runtime_error("WHERE IS THE PAIR?!\n");
}

void PmergeMe::insertSmallVec(Vec& bigs, Vec& smalls, Object& leftover) {
    std::vector<int> jacobsthal = generateJacobsthal(leftover._value != -1 ? bigs.size() + 2 : bigs.size() + 1);
    // Assign each number in sorted list index to track it after insertions
    for (size_t i = 0; i < bigs.size(); ++i)
        bigs[i].jacobsthalNumber = static_cast<int>(i);
    //Needed for later
    const int refSize = static_cast<int>(bigs.size());
    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        int index = jacobsthal[i];
        if (index == refSize && leftover._value != -1) binaryInsertVec(bigs, leftover, bigs.size());
        else findInsertVec(bigs, smalls, index);
    }
    // Erase indexes for this depth of recursion, !not for leftover! it still has a pair somewhere :3
    for (size_t i = 0; i < bigs.size(); ++i) {
        Object& obj = bigs[i];
        if (obj.isLeftover) obj.isLeftover = false;
        else if (!obj.pairs.empty()) obj.pairs.pop_back();
        obj.jacobsthalNumber = -1;
    }
}

Vec PmergeMe::mergeInsertionVec(Vec& vec) {
	if (vec.size() <= 1)
		return vec;
	Object leftover(-1);
	if (vec.size() % 2 == 1) {
		leftover = vec.back();
		leftover.jacobsthalNumber = -1;
		leftover.isLeftover = true;
		vec.pop_back();
	}
	//Step 1: Pairs
	counter += pairemUp(vec);
	//Step 2: divide into 2 arrays
	Vec smalls = collectSmalls(vec);
	Vec bigs = collectBigs(vec);
	//Step 3: call step 1 
	Vec sorted = mergeInsertionVec(bigs);
	//Step 4: insert and return 
	insertSmallVec(sorted, smalls, leftover);
	return sorted;
}