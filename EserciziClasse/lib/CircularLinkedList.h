
#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <stdexcept>

namespace mystl {

template<typename T>
class CLinkedList {
private:
	class Node {
		friend class CLinkedList;
	private:
		T value;
		Node* next;
		Node(T,Node* = nullptr);
		~Node();
	};
public:
	class Iterator {
		friend class CLinkedList;
	private:
		Iterator(Node*,size_t = 0);
		Node* point;
		const Node* firstnode;
		size_t lap;
	public:
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;
		T& operator*() const;
		T* operator->() const;
		Iterator& operator++();
		Iterator& operator++(int);
		bool operator==(const Iterator&) const;
		bool operator!=(const Iterator&) const;
		size_t getLap() const;
	};
private:
	Node* cur;
	size_t n;
	// number of nodes attached
public:
	CLinkedList();
	// default constructor: create empty list
	CLinkedList(size_t, const T& = T());
	// create a list with #1 elements of value #2
	~CLinkedList();
	// delete cursor node and all attached nodes
	bool empty() const;
	// returns true if list is empty
	size_t size() const;
	// returns number of elements stored in the list
	void push_front(const T&);
	// adds element after cursor
	void push_back(const T&);
	// adds element after cursor and advance list
	const T& front() const;
	// returns value after cursor node
	const T& back() const;
	// returns cursor node stored value
	void pop_front();
	// removes node after cursor
	void advance();
	// moves cursor forward
	Iterator begin() const;
	// return iterator to begin
	Iterator end(size_t = 1) const;
	// return iterator to end after #1 laps
	void clear();
	// removes every element in list
};



// Node //

template<typename T>
CLinkedList<T>::Node::Node(T v, Node* n) : value{v}, next{n} {}

template<typename T>
CLinkedList<T>::Node::~Node() {
	delete next;
	return;
}

// Iterator //

template<typename T>
CLinkedList<T>::Iterator::Iterator(Node* p, size_t s) : point{p}, firstnode{p}, lap{s} {}

template<typename T>
T& CLinkedList<T>::Iterator::operator*() const {
	return point->value;
}

template<typename T>
T* CLinkedList<T>::Iterator::operator->() const {
	return &point->value;
}


template<typename T>
typename CLinkedList<T>::Iterator& CLinkedList<T>::Iterator::operator++() {
	point = point->next;
	if(point == firstnode) ++lap;
	return *this;
}

template<typename T>
typename CLinkedList<T>::Iterator& CLinkedList<T>::Iterator::operator++(int) {
	const Iterator& temp = *this;
	point = point->next;
	if(point == firstnode) ++lap;
	return temp;
}

template<typename T>
bool CLinkedList<T>::Iterator::operator==(const Iterator& rhs) const {
	return (this->point == rhs.point) && (this->lap == rhs.lap);
}

template<typename T>
bool CLinkedList<T>::Iterator::operator!=(const Iterator& rhs) const {
	return !(*this == rhs);
}

template<typename T>
size_t CLinkedList<T>::Iterator::getLap() const {return lap;}

// CLinkedList //

template<typename T>
CLinkedList<T>::CLinkedList() : cur{nullptr}, n{0} {}

template<typename T>
CLinkedList<T>::CLinkedList(size_t amt, const T& val) : cur{nullptr}, n{0} {
	for(int i = 0; i < amt; i++) push_back(val);
}

template<typename T>
CLinkedList<T>::~CLinkedList() {
	if(!empty()) {
		Node* temp = cur->next;
		cur->next = nullptr;
		delete temp;
	}
}

template<typename T>
void CLinkedList<T>::clear() {
	this->~CLinkedList();
	cur = nullptr;
	n = 0;
	return;
}

template<typename T>
bool CLinkedList<T>::empty() const {return cur == nullptr;}

template<typename T>
size_t CLinkedList<T>::size() const {return this->n;}

template<typename T>
void CLinkedList<T>::push_front(const T& val) {
	if(empty()) {
		cur = new Node(val, nullptr);
		cur->next = cur;
	} else cur->next = new Node(val, cur->next);
	++n;
	return;
}

template<typename T>
void CLinkedList<T>::push_back(const T& val) {
	if(empty()) {
		cur = new Node(val, nullptr);
		cur->next = cur;
	} else cur->next = new Node(val, cur->next);
	++n;
	cur = cur->next;
	return;
}

template<typename T>
const T& CLinkedList<T>::front() const {
	if(empty()) throw std::runtime_error("LinkedList is empty");
	return cur->next->value;
}

template<typename T>
const T& CLinkedList<T>::back() const {
	if(empty()) throw std::runtime_error("LinkedList is empty");
	return cur->value;
}

template<typename T>
void CLinkedList<T>::pop_front() {
	if(empty()) throw std::runtime_error("LinkedList is empty");
	if(n == 1) {
		cur->next = nullptr;
		delete cur;
		cur = nullptr;
	} else {
		Node* temp = cur->next;
		cur->next = cur->next->next;
		temp->next = nullptr;
		delete temp;
	}
	--n;
	return;
}

template<typename T>
void CLinkedList<T>::advance() {
	if(empty()) throw std::runtime_error("LinkedList is empty");
	cur = cur->next;
	return;
}

template<typename T>
typename CLinkedList<T>::Iterator CLinkedList<T>::begin() const {
	return Iterator(cur->next);
}

template<typename T>
typename CLinkedList<T>::Iterator CLinkedList<T>::end(size_t s) const {
	return Iterator(cur->next,s);
}

}// end namespace mystl

#endif












//
