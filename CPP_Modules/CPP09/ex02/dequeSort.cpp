#include "PmergeMe.hpp"

const Deq PmergeMe::sortDeq(int ac, char *av[]) {
	Deq input;
	checkInputDeq(ac, av, input);
	std::cout << "\nBefore: ";
	dump<Deq, DeqConstIt>(input);
	std::clock_t start = std::clock();
	Deq sorted = mergeInsertionDeq(input);
	std::clock_t end = std::clock();
	std::cout << "\nAfter: ";
	dump<Deq, DeqConstIt> (sorted);
	std::cout << "\nTime to process the range of " 
				<< input.size() << " with std::deque : " 
				<< static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0 << " microsecs\n";
	std::cout << "Number of comparisons: " << counter << "\n";
	return sorted;
}

void PmergeMe::checkInputDeq(int ac, char *av[], Deq& deq) {
	for (int i = 1; i < ac; ++i) {
		const std::string arg(av[i]);
		if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
			throw std::invalid_argument("Invalid input => " + arg + "\n");
		int number = toInt(arg);
		deq.push_back(Object(number));
	}
}

static std::deque<int> fillSequence(const std::deque<int>& jacobsthal, int size) {
	std::deque<int> result;
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

static std::deque<int> generateJacobsthal(int size) {
    if (size <= 0) return std::deque<int>();
    
	std::deque<int> jacobsthal;
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

int pairemUp(Deq& deq) {
	int index = 0;
	int counter = 0;
	for (size_t i = 0; i < deq.size(); i += 2) {
		if (deq[i] > deq[i + 1]) {
			std::swap(deq[i], deq[i + 1]);
		}
		counter++;
		deq[i].pairs.push_back(index);
		deq[i + 1].pairs.push_back(index);
		deq[i].jacobsthalNumber = -1;
		deq[i + 1].jacobsthalNumber = -1;
		index++;
	}
	return counter;
}

Deq collectSmalls(const Deq& deq) {
	Deq smalls;
	for (size_t i = 0; i < deq.size(); i += 2) {
		smalls.push_back(deq[i]);
	}
	return smalls;
}

Deq collectBigs(const Deq& deq) {
	Deq bigs;
	for (size_t i = 1; i < deq.size(); i += 2) {
		bigs.push_back(deq[i]);
	}
	return bigs;
}

void PmergeMe::binaryInsertDeq(Deq& bigs, const Object& obj, int dist) {
	DeqIt low = bigs.begin();
	DeqIt high = bigs.begin() + dist;

	while (low != high) {
		DeqIt mid = low + std::distance(low, high) / 2;
		if (*mid > obj) high = mid;
		else low = mid + 1;
		counter++;
	}
	bigs.insert(low, obj);
}

void PmergeMe::findInsertDeq(Deq& bigs, const Deq& smalls, int index) {
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
            binaryInsertDeq(bigs, small, bigPos);
            return;
        }
    }
    throw std::runtime_error("WHERE IS THE PAIR?!\n");
}

void PmergeMe::insertSmallDeq(Deq& bigs, Deq& smalls, Object& leftover) {
    std::deque<int> jacobsthal = generateJacobsthal(leftover._value != -1 ? bigs.size() + 2 : bigs.size() + 1);
    // Assign each number in sorted list index to track it after insertions
    for (size_t i = 0; i < bigs.size(); ++i)
        bigs[i].jacobsthalNumber = static_cast<int>(i);
    //Needed for later
    const int refSize = static_cast<int>(bigs.size());
    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        int index = jacobsthal[i];
        if (index == refSize && leftover._value != -1) binaryInsertDeq(bigs, leftover, bigs.size());
        else findInsertDeq(bigs, smalls, index);
    }
    // Erase indexes for this depth of recursion, !not for leftover! it still has a pair somewhere :3
    for (size_t i = 0; i < bigs.size(); ++i) {
        Object& obj = bigs[i];
        if (obj.isLeftover) obj.isLeftover = false;
        else if (!obj.pairs.empty()) obj.pairs.pop_back();
        obj.jacobsthalNumber = -1;
    }
}

Deq PmergeMe::mergeInsertionDeq(Deq& deq) {
	if (deq.size() <= 1)
		return deq;
	Object leftover(-1);
	if (deq.size() % 2 == 1) {
		leftover = deq.back();
		leftover.jacobsthalNumber = -1;
		leftover.isLeftover = true;
		deq.pop_back();
	}
	//Step 1: Pairs
	counter += pairemUp(deq);
	//Step 2: divide into 2 arrays
	Deq smalls = collectSmalls(deq);
	Deq bigs = collectBigs(deq);
	//Step 3: call step 1 
	Deq sorted = mergeInsertionDeq(bigs);
	//Step 4: insert and return 
	insertSmallDeq(sorted, smalls, leftover);
	return sorted;
}