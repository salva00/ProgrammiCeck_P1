
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iterator>

namespace mystl {

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
	private:
		Iterator(Node*);
		Node* point;
	public:
		using iterator_category = std::bidirectional_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;
		T& operator*() const;
		T* operator->() const;
		Iterator& operator++();
		Iterator operator++(int);
		Iterator operator+(size_t) const;
		Iterator& operator--();
		Iterator operator--(int);
		Iterator operator-(size_t) const;
		bool operator==(const Iterator&) const;
		bool operator!=(const Iterator&) const;
		operator bool() const;
	};
private:
	Node* head;
	// first node: does not store data!
	Node* tail;
	// last node: does not store data!
	size_t n;
	// number of nodes attached
protected:
	Node* erase(const Node*);
	// delete node and return pointer to next
public:
	DLinkedList();
	// default constructor: create empty list
	DLinkedList(size_t, const T& = T());
	// create a list with #1 elements of value #2
	DLinkedList(const DLinkedList<T>&);
	// copy constructor
	~DLinkedList();
	// delete all nodes
	DLinkedList& operator=(const DLinkedList<T>&);
	// copy assignment
	bool empty() const;
	// return true if list is empty
	void push_back(const T&);
	// add element at the end
	void push_front(const T&);
	// add element at the beginning
	const T& back() const;
	// return last element
	const T& front() const;
	// return first element
	Iterator begin() const;
	// return iterator to first element
	Iterator end() const;
	// return iterator to last element
	Iterator rbegin() const;
	// return iterator to reverse begin
	Iterator rend() const;
	// return iterator to reverse end
	size_t size() const;
	// return number of elements stored
	Iterator erase(const Iterator&);
	// erase node pointed by iterator and return iterator to next
	void erase_before(const Iterator&);
	// erase node before iterator
	void erase_after(const Iterator&);
	// erase node after iterator
	void insert_before(const Iterator&, const T&);
	// insert element #2 before iterator #1
	void insert_after(const Iterator&, const T&);
	// insert element #2 after iterator #1
	void pop_back();
	// delete last element
	void pop_front();
	// delete first element
	void clear();
	// list empty
};



// Node //

template<typename T>
DLinkedList<T>::Node::Node(T val, Node* pre, Node* nex) : value{val}, prev{pre}, next{nex} {}

template<typename T>
DLinkedList<T>::Node::Node(Node* pre, Node* nex) : prev{pre}, next{nex} {} //, value{} //use default constructor?

template<typename T>
DLinkedList<T>::Node::~Node() {delete next;}

// Iterator //

template<typename T>
DLinkedList<T>::Iterator::Iterator(Node* p) : point{p} {}

template<typename T>
T& DLinkedList<T>::Iterator::operator*() const {return point->value;}

template<typename T>
T* DLinkedList<T>::Iterator::operator->() const {return &point->value;}

template<typename T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++() {
	if(point->next != nullptr) point = point->next;
	return *this;
}

template<typename T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int) {
	Iterator temp = *this;
	if(point->next != nullptr) point = point->next;
	return temp;
}

template<typename T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator+(size_t amt) const {
	Iterator res = *this;
	for(size_t i = 0; i < amt; ++i) ++res;
	return res;
}

template<typename T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator--() {
	if(point->prev != nullptr) point = point->prev;
	return *this;
}

template<typename T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator--(int) {
	Iterator temp = *this;
	if(point->prev != nullptr) point = point->prev;
	return temp;
}

template<typename T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator-(size_t amt) const {
	Iterator res = *this;
	for(size_t i = 0; i < amt; ++i) --res;
	return res;
}

template<typename T>
bool DLinkedList<T>::Iterator::operator==(const Iterator& rhs) const {
	return this->point == rhs.point;
}

template<typename T>
bool DLinkedList<T>::Iterator::operator!=(const Iterator& rhs) const {
	return this->point != rhs.point;
}

template<typename T>
DLinkedList<T>::Iterator::operator bool() const {
	return point != nullptr;
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
DLinkedList<T>::DLinkedList(size_t amt, const T& val) : n{amt} {
	head = new Node();
	tail = new Node();
	head->next = tail;
	tail->prev = head;
	for(int i = 0; i < amt; i++) push_back(val);
}

template<typename T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList<T>& rhs) {
	this->clear();
	for(Iterator it = rhs.begin(); it != rhs.end(); ++it) {
		this->push_back(*it);
	}
	return *this;
}

template<typename T>
DLinkedList<T>::DLinkedList(const DLinkedList<T>& list) : DLinkedList() {
	*this = list;
}

template<typename T>
DLinkedList<T>::~DLinkedList() {
	if(head) delete head;
}

template<typename T>
bool DLinkedList<T>::empty() const {
	return head->next == tail;
}

template<typename T>
void DLinkedList<T>::push_back(const T& val) {
	insert_before(end());
	return;
}

template<typename T>
void DLinkedList<T>::push_front(const T& val) {
	insert_after(begin());
	return;
}

template<typename T>
void DLinkedList<T>::insert_before(const Iterator& it, const T& val) {
	if(it.point->prev == nullptr) throw std::invalid_argument("Out of bounds");
	it.point->prev->next = new Node(val, it.point->prev, it.point);
	it.point->prev = it.point->prev->next;
	++n;
	return;
}

template<typename T>
void DLinkedList<T>::insert_after(const Iterator& it, const T& val) {
	if(it.point->next == nullptr) throw std::invalid_argument("Out of bounds");
	it.point->next->prev = new Node(val, it.point, it.point->next);
	it.point->next = it.point->next->prev;
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
	return Iterator(tail->prev);
}

template<typename T>
typename DLinkedList<T>::Iterator DLinkedList<T>::rend() const {
	return Iterator(head);
}

template<typename T>
size_t DLinkedList<T>::size() const {return this->n;}

template<typename T>
typename DLinkedList<T>::Node* DLinkedList<T>::erase(const Node* ptr) {
	if(ptr == head || ptr == tail || ptr==nullptr) throw std::invalid_argument("Out of bounds");
	ptr->prev->next = ptr->next;
	ptr->next->prev = ptr->prev;
	Node* res = ptr->next;
	ptr->next = nullptr, ptr->prev = nullptr;
	delete ptr;
	--n;
	return res;
}

template<typename T>
typename DLinkedList<T>::Iterator DLinkedList<T>::erase(const Iterator& it) {
	return Iterator(erase(it->point));
}

template<typename T>
void DLinkedList<T>::erase_before(const Iterator& it) {
	erase(it->ptr->prev);
}

template<typename T>
void DLinkedList<T>::erase_after(const Iterator& it) {
	erase(it->ptr->next);
}

template<typename T>
void DLinkedList<T>::pop_back() {
	erase(rbegin());
	return;
}

template<typename T>
void DLinkedList<T>::pop_front() {
	erase(begin());
	return;
}

template<typename T>
void DLinkedList<T>::clear() {
	if(empty()) return;
	Node* temp = head->next;
	head->next->prev = nullptr;
	tail->prev->next = nullptr;
	delete temp;
	head->next = tail;
	tail->prev = head;
	n = 0;
	return;
}

}// end namespace mystl

#endif













//
