#include "PmergeMe.hpp"

template <typename Container, typename iterator>
bool isSorted(const Container& container) {
	iterator it = container.begin();
	while (it != container.end()) {
		iterator second = it + 1;
		if (second != container.end() && *it > *second)
			return false;
		it++;
	}
	return true;
}

int main(int ac, char *av[])
{
	if (ac < 2) {
		std::cout << "Error: PROVIDE SOME POSITIVE NUMBERS!\n";
		return 1;
	}
	try {
		PmergeMe vecMerger;
		Vec vec = vecMerger.sortVec(ac, av);
		if (isSorted<Vec, VecConstIt>(vec))
			std::cout << "Container is indeed sorted!\n";
		else std::cout << "Container is not sorted!\n";
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	try {
		PmergeMe deqMerger;
		Deq deq = deqMerger.sortDeq(ac, av);
		if (isSorted<Deq, DeqConstIt>(deq))
			std::cout << "Container is indeed sorted!\n";
		else std::cout << "Container is not sorted!\n";
	} catch (std::exception& e) {
		std::cout << e.what();
	}
}