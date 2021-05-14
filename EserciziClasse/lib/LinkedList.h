
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>

template<typename T>
class LinkedList {
private:
	class Node {
		friend class LinkedList;
	private:
		T value;
		Node* next;
		Node(T,Node* = nullptr);
		~Node();
	};
public:
	class Iterator {
		friend class LinkedList;
	public:
		T& operator*();
		Iterator& operator++();
		Iterator& operator++(int);
		bool operator==(const Iterator&) const;
		bool operator!=(const Iterator&) const;
	private:
		Iterator(Node*);
		Node* point;
	};
private:
	Node* head;
	size_t n;
public:
	LinkedList();
	LinkedList(size_t, T = 0);
	~LinkedList();
	bool empty() const;
	const T& front() const;
	void push_front(const T&);
	void pop_front();
	size_t size() const;
	Iterator begin() const;
	Iterator end() const;
	void erase_after(const Iterator&);
};


// Node //

template<typename T>
LinkedList<T>::Node::Node(T v, Node* n) : value{v}, next{n} {}

template<typename T>
LinkedList<T>::Node::~Node() {
	delete next;
	return;
}

// Iterator //

template<typename T>
T& LinkedList<T>::Iterator::operator*() {
	return point->value;
}

template<typename T>
LinkedList<T>::Iterator::Iterator(Node* p) : point{p} {}

template<typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++() {
	if(point == nullptr) throw std::runtime_error("Nullpointer exception. Reached list end");
	point = point->next;
	return *this;
}

template<typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++(int) {
	if(point == nullptr) throw std::runtime_error("Nullpointer exception. Reached list end");
	const Iterator& temp = *this;
	this->point = point->next;
	return temp;
}

template<typename T>
bool LinkedList<T>::Iterator::operator==(const Iterator& rhs) const {
	return this->point == rhs.point;
}

template<typename T>
bool LinkedList<T>::Iterator::operator!=(const Iterator& rhs) const {
	return this->point != rhs.point;
}

// Linked List //

template<typename T>
LinkedList<T>::LinkedList() : head{nullptr}, n{0} {}

template<typename T>
LinkedList<T>::LinkedList(size_t amount, T val) : head{nullptr}, n{amount} {
	for(size_t i = 0; i < amount; i++) push_front(val);
}

template<typename T>
LinkedList<T>::~LinkedList() {
	delete head;
	return;
}

template<typename T>
bool LinkedList<T>::empty() const {return this->head==nullptr;}

template<typename T>
const T& LinkedList<T>::front() const {
	if(empty()) throw std::runtime_error("LinkedList is empty");
	return head->value;
}

template<typename T>
void LinkedList<T>::push_front(const T& value) {
	// head = new Node(value, head);
	Node* temp = new Node(value);
	temp->next = head;
	head = temp;
	++n;
	return;
}

template<typename T>
void LinkedList<T>::pop_front() {
	if(empty()) throw std::runtime_error("LinkedList is empty");
	Node* popped = head;
	head = head->next;
	popped->next = nullptr;
	delete popped;
	--n;
	return;
}

template<typename T>
size_t LinkedList<T>::size() const {return this->n;}

template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() const {
	return Iterator(head);
}

template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end() const {
	return Iterator(nullptr);
}

template<typename T>
void LinkedList<T>::erase_after(const Iterator& it) {
	Node* temp = it.point->next;
	if(temp == nullptr) throw std::invalid_argument("Index out of bounds");
	it.point->next = temp->next;
	temp->next = nullptr;
	delete temp;
	return;
}

#endif








//
