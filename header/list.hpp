#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include "node.hpp"

template <typename T>
class ListIterator {
public:
    using DifferenceType = ptrdiff_t;
    using ValueType = T;
    using PointerType = T*;
    using ReferenceType = T&;
    using IteratorCategory = std::forward_iterator_tag;

public:
    ListIterator(Node<T>* node)
		: m_Ptr(node) {}

	/*--------------------------------------------------*/

    T& operator*() {
		return m_Ptr->m_tData;
	}

    T* operator->() {
		return &(m_Ptr->m_tData);
	}

    ListIterator& operator++() {
		m_Ptr = m_Ptr->m_nNext;
		return *this;
	}

    ListIterator operator++(int) {
		ListIterator tmp(*this);
		++(*this); return tmp;
	}

	// Why do I segfault here?
    ListIterator& operator--() {
		m_Ptr = m_Ptr->m_nPrev;
		return *this;
	}

    ListIterator operator--(int) {
		ListIterator tmp(*this);
		--(*this); return tmp;
	}

	/*--------------------------------------------------*/

    bool operator==(const ListIterator& rhs) {
		return m_Ptr == rhs.m_Ptr;
	}

    bool operator!=(const ListIterator& rhs) {
		return m_Ptr != rhs.m_Ptr;
	}

//private:
    Node<T>* m_Ptr;
};

template<class T>
class List : private Node<T> {
public:
	using ValueType = T;
	using Iterator = ListIterator<ValueType>;

public:
	List(std::initializer_list<ValueType> init = {}) {
		this->m_nHead = nullptr;
		this->m_nTail = nullptr;
		for (auto i : init) {
			this->PushBack(i);
		}
	}

	~List() {};

	/*--------------------------------------------------*/

	Iterator begin() {
		return Iterator(this->m_nHead);
	}

	Iterator end() {
		return Iterator(nullptr);
	}

	/*--------------------------------------------------*/

	bool Empty() {
		return !this->m_nHead;
	}

    int Size() {
        int size = 0;
        while (this->m_nHead) {
            ++size;
            this->m_nHead = this->m_nHead->m_nNext;
        }
        return size;
    }

	/*--------------------------------------------------*/

	Node<ValueType>* Front() {
		return this->m_nHead;
	}

	Node<ValueType>* Back() {
		return this->m_nTail;
	}

	/*--------------------------------------------------*/

	void PushFront(ValueType data) {
		this->Insert(this->begin(), data);
	}

	ValueType PopFront() {
		if (!this->m_nHead->m_nNext) return -1;
		ValueType data = this->m_nHead->m_tData;
		this->m_nHead->m_nNext = this->m_nHead->m_nNext->m_nNext;
		return data;
	}

	void PushBack(ValueType data) {
		Node<ValueType>* node = new Node<ValueType>(data);
		if (!this->m_nHead || !this->m_nTail) {
			this->m_nHead = node;
			this->m_nTail = node;
		} else {
			this->Insert(this->end(), data);
		}
	}

	ValueType PopBack() {
		if (!this->m_nTail->m_nPrev) return -1;
		ValueType data = this->m_nTail->m_tData;
		// Create pointer to current tail to delete later
		Node<ValueType>* node = this->m_nTail;
		// Tail needs to now point to the previous node
		this->m_nTail = this->m_nTail->m_nPrev;
		// And it should not point to any "next" node
		this->m_nTail->m_nNext = nullptr;
		// Delete old tail
		delete node;
		return data;
	}

	void Insert(Iterator pos, ValueType data) {
		Node<ValueType>* node = new Node<ValueType>(data);
		if (pos == this->begin()) {
			node->m_nNext = this->m_nHead;
			this->m_nHead = node;
		} else if (pos == this->end()) {
			node->m_nPrev = this->m_nTail;
			this->m_nTail->m_nNext = node;
			this->m_nTail = node;
		} else {
			node->m_nNext = pos.m_Ptr->m_nNext;
			node->m_nPrev = pos.m_Ptr;
			pos.m_Ptr->m_nNext->m_nPrev = node;
			pos.m_Ptr->m_nNext = node;
		}
	}

	void Erase(Iterator pos) {
		if (pos == this->begin()) {
			this->PopFront();
		} else if (pos == this->end()) {
			this->PopBack();
		} else {
			pos.m_Ptr->m_nPrev->m_nNext = pos.m_Ptr->m_nNext;
			pos.m_Ptr->m_nNext->m_nPrev = pos.m_Ptr->m_nPrev;
		}
		delete pos.m_Ptr;
	}

	void Resize(int size) {
		if (size <= this->Size()) {
			while (this->Size() > size) this->PopBack();
		}
		else {
			while (this->Size() < size) this->PushBack(0);
		}
	}

	void Clear() {
		while (!this->Empty())
			this->PopBack();
	}

	/*--------------------------------------------------*/

	// Custom stuff here?

private:
	Node<ValueType>* m_nHead;
	Node<ValueType>* m_nTail;
};

#endif