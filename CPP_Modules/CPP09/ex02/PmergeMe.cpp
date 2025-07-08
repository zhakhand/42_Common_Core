#include "PmergeMe.hpp"
#include "Object.hpp"
#include <limits>

PmergeMe::PmergeMe() : counter(0){}

PmergeMe::PmergeMe(const PmergeMe& other){(void)other;}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {(void)other; return *this;}

PmergeMe::~PmergeMe() {}

int PmergeMe::toInt(const std::string& number) {
    int res = 0;
    const char* str = number.c_str();

    for (const char* p = str; *p != '\0'; ++p) {
        int digit = *p - '0';
        if (res > (std::numeric_limits<int>::max() - digit) / 10) {
            throw std::runtime_error("Int Overflow => " + number + "\n");
        }
        res = res * 10 + digit;
    }
    return res;
}
