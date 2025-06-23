#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include "MutantStack.hpp"

std::string toLowerStr(std::string str) {
	for (size_t i = 0; i < str.length(); ++i)
		str.at(i) = std::tolower(static_cast<unsigned char>(str.at(i)));
	return str;
}

int main() {
	{
		std::cout << "\n***** MutantStack Test *****\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "\nTop of the stack: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "\nStack size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "\nStack size: " << mstack.size() << std::endl;
		std::cout << "\nElements of the stack: ";
		while (it != ite) {
			std::cout << *it << (ite - it == 1 ? "\n" : ", ");
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << "\nElements of the copied stack: ";
		while (!s.empty()) {
			std::cout << s.top() << (s.size() == 1 ? "\n" : ", ");
			s.pop();
		}
	}
	{
		std::cout << "\n***** List Test *****\n";
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << "\nTop of the list: " << lst.back() << std::endl;
		lst.pop_back();
		std::cout << "\nList size: " << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		std::cout << "\nList size: " << lst.size() << std::endl;
		std::cout << "\nElements of the list: ";
		while (it != ite) {
			std::cout << *it << (*it == lst.back() ? "\n" : ", ");
			++it;
		}
	}
	{
		std::cout << "\n***** Iterator & ConstIterator Test\n";
		MutantStack<std::string> mStack1;
		MutantStack<std::string> mStack2;
		std::vector<std::string> strings;
		strings.push_back("HelLO");
		strings.push_back("WorLD");
		strings.push_back("I AM");
		strings.push_back("piZZa");
		
		for (size_t i = 0; i < strings.size(); ++i) {
			mStack1.push(strings.at(i));
			mStack2.push(strings.at(i));
		}
		MutantStack<std::string>::iterator itB = mStack1.begin();
		MutantStack<std::string>::iterator itE = mStack1.end();
		MutantStack<std::string>::const_iterator citB = mStack2.begin();
		MutantStack<std::string>::const_iterator citE = mStack2.end();

		std::transform(itB, itE, itB, toLowerStr);
		//std::transform(citB, citE, citB, toLowerStr); // won't compile!
		std::cout << "\nAfter normal iterator: ";
		while (itB != itE) {
			std::cout << *itB << (itE - itB == 1 ? "\n" : ", ");
			++itB;
		}
		std::cout << "\nAfter const iterator: ";
		while (citB != citE) {
			std::cout << *citB << (citE - citB == 1 ? "\n" : ", ");
			++citB;
		}
	}
	{
		std::cout << "\n***** Iterator & ConstIterator Test\n";
		MutantStack<std::string> mStack1;
		MutantStack<std::string> mStack2;
		std::vector<std::string> strings;
		strings.push_back("HelLO");
		strings.push_back("WorLD");
		strings.push_back("I AM");
		strings.push_back("piZZa");
		
		for (size_t i = 0; i < strings.size(); ++i) {
			mStack1.push(strings.at(i));
			mStack2.push(strings.at(i));
		}
		MutantStack<std::string>::reverse_iterator itB = mStack1.rbegin();
		MutantStack<std::string>::reverse_iterator itE = mStack1.rend();
		MutantStack<std::string>::const_reverse_iterator citB = mStack2.rbegin();
		MutantStack<std::string>::const_reverse_iterator citE = mStack2.rend();

		std::transform(itB, itE, itB, toLowerStr);
		//std::transform(citB, citE, citB, toLowerStr); // won't compile!
		std::cout << "\nAfter normal iterator: ";
		while (itB != itE) {
			std::cout << *itB << (itE - itB == 1 ? "\n" : ", ");
			++itB;
		}
		std::cout << "\nAfter const iterator: ";
		while (citB != citE) {
			std::cout << *citB << (citE - citB == 1 ? "\n" : ", ");
			++citB;
		}
	}
	return 0;
}