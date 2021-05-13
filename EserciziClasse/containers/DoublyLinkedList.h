
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include<stdexcept>

template<typename T>
class DLinkedList {
private:
	class Node {
		friend class DLinkedList;
	private:
		Node(T, Node* = nullptr, Node* = nullptr);
		Node(Node* = nullptr, Node* = nullptr);
		~Node();
		T value;
		Node* prev;
		Node* next;
	};
public:
	class Iterator {
		friend class DLinkedList;
	public:
		T& operator*();
		Iterator& operator++();
		Iterator& operator++(int);
		Iterator& operator--();
		Iterator& operator--(int);
		bool operator==(const Iterator&) const;
		bool operator!=(const Iterator&) const;
	private:
		Iterator(Node*);
		Node* point;
	};
private:
	Node* head;
	Node* tail;
	size_t n;
public:
	DLinkedList();
	void push_back(const T&);
	void push_front(const T&);
	const T& back() const;
	const T& front() const;
	Iterator begin() const;
	Iterator end() const;
	Iterator rbegin() const;
	Iterator rend() const;
	size_t size() const;
	Iterator erase(const Iterator&);
	void pop_back();
	void pop_front();
};

// Node //

template<typename T>
DLinkedList<T>::Node::Node(T val, Node* pre, Node* nex) : value{val}, prev{pre}, next{nex} {}

template<typename T>
DLinkedList<T>::Node::Node(Node* pre, Node* nex) : prev{pre}, next{nex} {}

template<typename T>
DLinkedList<T>::Node::~Node() {delete this->next; delete this->prev;}

// Iterator //

template<typename T>
DLinkedList<T>::Iterator::Iterator(Node* p) : point{p} {}

template<typename T>
T& DLinkedList<T>::Iterator::operator*() {return point->value;}

template<typename T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++() {
	if(point->next == nullptr) throw std::runtime_error("Nullpointer exception. Reached list end");
	point = point->next;
	return *this;
}

template<typename T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++(int) {
	if(point->next = nullptr) throw std::runtime_error("Nullpointer exception. Reached list end");
	Iterator& temp = *this;
	this->point = point->next;
	return temp;
}

template<typename T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator--() {
	if(point->prev == nullptr) throw std::runtime_error("Nullpointer exception. Reached list end");
	point = point->prev;
	return *this;
}

template<typename T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator--(int) {
	if(point->prev = nullptr) throw std::runtime_error("Nullpointer exception. Reached list end");
	Iterator& temp = *this;
	this->point = point->prev;
	return temp;
}

template<typename T>
bool DLinkedList<T>::Iterator::operator==(const Iterator& rhs) const {
	return this->point == rhs.point;
}

template<typename T>
bool DLinkedList<T>::Iterator::operator!=(const Iterator& rhs) const {
	return this->point != rhs.point;
}

// DLinkedList //

template<typename T>
DLinkedList<T>::DLinkedList() : n{0} {
	head = new Node();
	tail = new Node();
	head->next = tail;
	tail->prev = head;
}

template<typename T>
void DLinkedList<T>::push_back(const T& val) {
	tail->value = val;
	tail->next = new Node(tail,nullptr);
	tail = tail->next;
	++n;
	return;
}

template<typename T>
void DLinkedList<T>::push_front(const T& val) {
	head->value = val;
	head->prev = new Node(nullptr,head);
	head = head->prev;
	++n;
	return;
}

template<typename T>
const T& DLinkedList<T>::back() const {
	if(tail->prev == head) throw std::runtime_error("List is empty");
	return tail->prev->value;
}

template<typename T>
const T& DLinkedList<T>::front() const {
	if(head->next == tail) throw std::runtime_error("List is empty");
	return head->next->value;
}

template<typename T>
typename DLinkedList<T>::Iterator DLinkedList<T>::begin() const {
	return Iterator(head->next);
}

template<typename T>
typename DLinkedList<T>::Iterator DLinkedList<T>::end() const {
	return Iterator(tail);
}

template<typename T>
typename DLinkedList<T>::Iterator DLinkedList<T>::rbegin() const {
	return Iterator(head);
}

template<typename T>
typename DLinkedList<T>::Iterator DLinkedList<T>::rend() const {
	return Iterator(tail->prev);
}

template<typename T>
size_t DLinkedList<T>::size() const {return this->n;}

template<typename T>
typename DLinkedList<T>::Iterator DLinkedList<T>::erase(const Iterator& it) {
	if(it.point == head || it.point == tail) throw std::invalid_argument("Out of bounds");
	it.point->prev->next = it.point->next;
	it.point->next->prev = it.point->prev;
	Node* temp = it.point->next;
	it.point->next = nullptr;
	it.point->prev = nullptr;
	delete it.point;
	--n;
	return temp;
}

template<typename T>
void DLinkedList<T>::pop_back() {
	erase(--end());
	return;
}

template<typename T>
void DLinkedList<T>::pop_front() {
	erase(begin());
	return;
}

#endif













//
