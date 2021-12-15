#include <iostream>
#include "header/list.hpp"

int main() {
# if 0
	List<int> myList = { 2, 3, 4, 5 };

	myList.PushBack(6);
	myList.PushFront(1);
	List<int>::Iterator it = myList.end();
	myList.Insert(it, 7);
	myList.Resize(3);
	myList.PushBack(4);
	myList.Erase(it);

	std::cout << "Iterator for-each print:" << std::endl;
	for (const auto& data : myList) {
		std::cout << data << std::endl;
	}
#endif

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