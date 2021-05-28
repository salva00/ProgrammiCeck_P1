
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>

namespace mystl {

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
	private:
		Iterator(Node*);
		Node* point;
	public:
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;
		T& operator*();
		T* operator->();
		Iterator& operator++();
		Iterator& operator++(int);
		bool operator==(const Iterator&) const;
		bool operator!=(const Iterator&) const;
	};
private:
	Node* head;
	size_t n;
	// number of nodes attached
public:
	LinkedList();
	// default constructor: create empty list
	LinkedList(size_t, const T& = T());
	// creates a list with #1 elements of value #2
	LinkedList(const LinkedList&);
	// copy constructor
	LinkedList& operator=(const LinkedList&);
	// copy assignment
	~LinkedList();
	// delete all nodes
	bool empty() const;
	// returns true if list is empty
	const T& front() const;
	// returns first element
	void push_front(const T&);
	// adds element at the beginning
	void pop_front();
	// deletes first element
	size_t size() const;
	// returns number of elements stored
	Iterator begin() const;
	// returns iterator to first element
	Iterator end() const;
	// returns iterator to last element
	void erase_after(const Iterator&);
	// erases element AFTER iterator
	void insert_after(const Iterator&, const T&);
	// insert element after iterator
	void clear();
	// list empty
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
T* LinkedList<T>::Iterator::operator->() {
	return &point->value;
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
LinkedList<T>::LinkedList(size_t amount, const T& val) : head{nullptr}, n{amount} {
	for(size_t i = 0; i < amount; i++) push_front(val);
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList& list) : head{nullptr} {
	*this = list;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& rhs) {
	if(!empty()) clear();
	if(rhs.empty()) {
		this->head = nullptr;
		this->n = 0;
	} else {
		this->head = new Node(rhs.head->value);
		for(Node *i = head, *j = rhs.head; j->next != nullptr; j = j->next, i = i->next) {
			i->next = new Node(j->next->value);
		}
		this->n = rhs.size();
	}
	return *this;
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

template<typename T>
void LinkedList<T>::insert_after(const Iterator& it, const T& val) {
	if(it.point == nullptr) throw std::invalid_argument("Index out of bounds");
	it.point->next = new Node(val, it.point->next);
	return;
}

template<typename T>
void LinkedList<T>::clear() {
	if(!empty()) {
		delete head;
		head = nullptr;
		n = 0;
	}
	return;
}

}//end namespace mystl

#endif








//