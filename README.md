# List

## FAQ

### What is it?
It is my "version" of C++'s std::list container, which is a doubly-linked list.

### Why did I make it?
We are going through linked lists in my class, and I'm not allowed to use C++'s built-in std::list, but I am allowed to use this.

## Usage

### Installing
```bash
git clone https://github.com/veasman/List.git
mv List/header/*.hpp <YOUR_DISIRED_LOCATION>
```

### Example
```cpp
// main.cpp
#include <iostream>
#include "list.hpp"

int main() {
	List<int> myList = { 0, 2, 3 };
	myList.PushBack(4);
	
	List<int>::Iterator itr = myList.begin();
	itr++;
	myList.Insert(itr, 1);

	for (const auto& num : myList) {
		cout << num << endl;
		// Expected output:
		// 0
		// 1
		// 2
		// 3
		// 4
	}
}
```

## Docs

Everything in the List class functions as it does in the built-in std::list class, but I'll explain anyways.

### begin()
Returns an iterator of the first element (head) of the list.

### end()
Returns an iterator of the last element (tail) in the list.

### Front()
Returns the first element (head) of the list as type Node<T\>*.

### Back()
Returns the last element (tail) of the list as type Node<T\>*.

### PushFront(T data)
Uses `Insert(Iterator pos, T data)` to place a new node at the front of the list.

### PopFront()
Removes the first element of the list, and returns the data from that element.

### PushBack(T data)
Uses `Insert(Iterator pos, T data)` to place a new node at the end of the list.

### PopBack()
Removes the last element from the list, and returns the data from that element.

### Insert(Iterator pos, T data)
Inserts `data` at the position of `pos`

### Erase(Iterator pos)
Erases the node at `pos`

### Resize(int size)
If `size` is less than the list's current size, it will add new nodes with `data` as `0` until the size is fully adjusted.

If `size` is greater than or equal to the list's current size, `PopBack` will be called until the size is fully adjusted.

### Clear()
Resets the list to contain no data.