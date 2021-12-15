#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
public:
	Node(T data = 0) {
		this->m_tData = data;
		this->m_nNext = nullptr;
		this->m_nPrev = nullptr;
	}
	~Node() {}

	bool operator==(const Node& b) const {
		return this->m_tData == b->m_tData;
	}

public:
	T m_tData;
	Node<T>* m_nNext;
	Node<T>* m_nPrev;
};

#endif