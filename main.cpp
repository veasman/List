#include <iostream>
#include "header/list.hpp"

int main() {
	List<int> myList = { 0, 1, 3 };
	myList.PushBack(4);
	
	List<int>::Iterator itr = myList.begin();
	itr++;
	myList.Insert(itr, 2);

	for (const auto& num : myList) {
		std::cout << num << std::endl;
		// Expected output:
		// 0
		// 1
		// 2
		// 3
		// 4
	}

	return 0;
}