#include <iostream>
#include "header/list.hpp"

int main() {
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

	return 0;
}