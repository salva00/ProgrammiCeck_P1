
#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include<stdexcept>

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
private:
	Node* cur;
	size_t n;
	//number of nodes attached
public:
	CLinkedList();
	//default constructor: create empty list
	CLinkedList(size_t, const T& = 0);
	//create a list with #1 elements of value #2
	~CLinkedList();
	//delete cursor node and all attached nodes
	bool empty() const;
	//returns true if list is empty
	size_t size() const;
	//returns number of elements stored in the list
	void push_front(const T&);
	//adds element after cursor
	void push_back(const T&);
	//adds element after cursor and advance list
	const T& front() const;
	//returns value after cursor node
	const T& back() const;
	//returns cursor node stored value
	void pop_front();
	//removes node after cursor
	void advance();
	//moves cursor forward
};



// Node //

template<typename T>
CLinkedList<T>::Node::Node(T v, Node* n) : value{v}, next{n} {}

template<typename T>
CLinkedList<T>::Node::~Node() {
	delete next;
	return;
}

// CLinkedList //

template<typename T>
CLinkedList<T>::CLinkedList() : cur{nullptr}, n{0} {}

template<typename T>
CLinkedList<T>::CLinkedList(size_t amt, const T& val) : cur{nullptr}, n{0} {
	for(int i = 0; i < amt; i++) push_back(val);
}

template<typename T>
CLinkedList<T>::~CLinkedList() {delete cur;}


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
	Node* temp = cur->next;
	cur->next = cur->next->next;
	temp->next = nullptr;
	delete temp;
	--n;
	return;
}

template<typename T>
void CLinkedList<T>::advance() {
	if(empty()) throw std::runtime_error("LinkedList is empty");
	cur = cur->next;
	return;
}

#endif












//
