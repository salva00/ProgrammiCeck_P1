
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iterator>
#include <type_traits>

#define CONST true
#define NONCONST false
#define REVERSE true
#define NONREVERSE false

namespace mystl {

template<typename T>
class DLinkedList {
private:
	class Node {
		friend class DLinkedList<T>;
	private:
		Node(T, Node* = nullptr, Node* = nullptr);
		Node(Node* = nullptr, Node* = nullptr);
		~Node();
		T value;
		Node* prev;
		Node* next;
	};
	template<bool is_const, bool is_reverse> class GenericIterator;
public:
	using Iterator = GenericIterator<NONCONST,NONREVERSE>;
	using ConstIterator = GenericIterator<CONST,NONREVERSE>;
	using ReverseIterator = GenericIterator<NONCONST,REVERSE>;
	using ConstReverseIterator = GenericIterator<CONST,REVERSE>;
private:
	Node* head;
	// first node: does not store data!
	Node* tail;
	// last node: does not store data!
	size_t n;
	// number of nodes attached
protected:
	Node* erase(Node*);
	// delete node and return pointer to next
public:
	DLinkedList();
	// default constructor: create empty list
	DLinkedList(size_t, const T&);
	// create a list with #1 elements of value #2
	DLinkedList(const DLinkedList<T>&);
	// copy constructor
	explicit DLinkedList(const std::initializer_list<T>&);
	// construct a list from initalizer list
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
	Iterator begin();
	ConstIterator begin() const;
	// return iterator to first element
	Iterator end();
	ConstIterator end() const;
	// return iterator to last element
	ReverseIterator rbegin();
	ConstReverseIterator rbegin() const;
	// return reverse iterator to reverse begin
	ReverseIterator rend();
	ConstReverseIterator rend() const;
	// return reverse iterator to reverse end
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
	Iterator insert_in_order(const T&);
	// insert #1 in an ordered list, keeping it ordered
	template<class Predicate> void remove_if(Predicate);
	// remove all elements for which predicate returns true
};

template<typename T>
template<bool is_const, bool is_reverse>
class DLinkedList<T>::GenericIterator {
	friend class DLinkedList<T>;
private:
	explicit GenericIterator(typename DLinkedList<T>::Node*);
	typename DLinkedList<T>::Node* point;
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = typename std::conditional<is_const, const T, T>::type;
	using pointer = typename std::conditional<is_const, const T*, T*>::type;
	using reference = typename std::conditional<is_const, const T&, T&>::type;
	reference operator*() const;
	pointer operator->() const;
	GenericIterator<is_const,is_reverse>& operator++();
	GenericIterator<is_const,is_reverse> operator++(int);
	GenericIterator<is_const,is_reverse> operator+(size_t) const;
	GenericIterator<is_const,is_reverse>& operator--();
	GenericIterator<is_const,is_reverse> operator--(int);
	GenericIterator<is_const,is_reverse> operator-(size_t) const;
	bool operator==(const GenericIterator<is_const, is_reverse>&) const;
	bool operator!=(const GenericIterator<is_const, is_reverse>&) const;
	operator bool() const;
	operator GenericIterator<CONST,is_reverse>();
	// Non Const => Const
	explicit GenericIterator(GenericIterator<is_const,!is_reverse>);
	// Reverse <=> Non reverse
};



// Node //

template<typename T>
DLinkedList<T>::Node::Node(T val, Node* pre, Node* nex) : value{val}, prev{pre}, next{nex} {}

template<typename T>
DLinkedList<T>::Node::Node(Node* pre, Node* nex) : prev{pre}, next{nex} {} //, value{} //use default constructor?

template<typename T>
DLinkedList<T>::Node::~Node() {delete next;}

// Iterator //

template<typename T> template<bool is_const, bool is_reverse>
DLinkedList<T>::GenericIterator<is_const,is_reverse>::GenericIterator(Node* p) : point{p} {}

template<typename T> template<bool is_const, bool is_reverse>
typename DLinkedList<T>::template GenericIterator<is_const,is_reverse>::reference DLinkedList<T>::GenericIterator<is_const,is_reverse>::operator*() const {
	return point->value;
}

template<typename T> template<bool is_const, bool is_reverse>
typename DLinkedList<T>::template GenericIterator<is_const,is_reverse>::pointer DLinkedList<T>::GenericIterator<is_const,is_reverse>::operator->() const {
	return &point->value;
}

template<typename T> template<bool is_const, bool is_reverse>
typename DLinkedList<T>::template GenericIterator<is_const,is_reverse>& DLinkedList<T>::GenericIterator<is_const,is_reverse>::operator++() {
	// if(point->next != nullptr) point = point->next;
	if(is_reverse) {
		if(point->prev) point = point->prev;
		else throw std::runtime_error("Reached End");
	} else {
		if(point->next) point = point->next;
		else throw std::runtime_error("Reached End");
	}
	return *this;
}

template<typename T> template<bool is_const, bool is_reverse>
typename DLinkedList<T>::template GenericIterator<is_const,is_reverse> DLinkedList<T>::GenericIterator<is_const,is_reverse>::operator++(int) {
	GenericIterator<is_const,is_reverse> temp = *this;
	this->operator++();
	return temp;
}

template<typename T> template<bool is_const, bool is_reverse>
typename DLinkedList<T>::template GenericIterator<is_const,is_reverse> DLinkedList<T>::GenericIterator<is_const,is_reverse>::operator+(size_t amt) const {
	GenericIterator<is_const,is_reverse> res = *this;
	for(size_t i = 0; i < amt; ++i) ++res;
	return res;
}

template<typename T> template<bool is_const, bool is_reverse>
typename DLinkedList<T>::template GenericIterator<is_const,is_reverse>& DLinkedList<T>::GenericIterator<is_const,is_reverse>::operator--() {
	if(is_reverse) {
		if(point->next) point = point->next;
		else throw std::runtime_error("Reached End");
	} else {
		if(point->prev) point = point->prev;
		else throw std::runtime_error("Reached End");
	}
	return *this;
}

template<typename T> template<bool is_const, bool is_reverse>
typename DLinkedList<T>::template GenericIterator<is_const,is_reverse> DLinkedList<T>::GenericIterator<is_const,is_reverse>::operator--(int) {
	GenericIterator<is_const,is_reverse> temp = *this;
	this->operator--();
	return temp;
}

template<typename T> template<bool is_const, bool is_reverse>
typename DLinkedList<T>::template GenericIterator<is_const,is_reverse> DLinkedList<T>::GenericIterator<is_const,is_reverse>::operator-(size_t amt) const {
	GenericIterator<is_const,is_reverse> res = *this;
	for(size_t i = 0; i < amt; ++i) --res;
	return res;
}

template<typename T> template<bool is_const, bool is_reverse>
bool DLinkedList<T>::GenericIterator<is_const,is_reverse>::operator==(const GenericIterator<is_const,is_reverse>& rhs) const {
	return this->point == rhs.point;
}

template<typename T> template<bool is_const, bool is_reverse>
bool DLinkedList<T>::GenericIterator<is_const,is_reverse>::operator!=(const GenericIterator<is_const,is_reverse>& rhs) const {
	return this->point != rhs.point;
}

template<typename T> template<bool is_const, bool is_reverse>
DLinkedList<T>::GenericIterator<is_const,is_reverse>::operator bool() const {
	return bool(point);
}

template<typename T> template<bool is_const, bool is_reverse>
DLinkedList<T>::GenericIterator<is_const,is_reverse>::operator GenericIterator<CONST,is_reverse>() {
	return GenericIterator<CONST,is_reverse>(this->point);
}

template<typename T> template<bool is_const, bool is_reverse>
DLinkedList<T>::GenericIterator<is_const,is_reverse>::GenericIterator(GenericIterator<is_const,!is_reverse> it)
	: GenericIterator{it.point} {};

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
DLinkedList<T>::DLinkedList(const std::initializer_list<T>& il) : DLinkedList() {
	for(auto i : il) push_back(i);
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
	insert_before(end(),val);
	return;
}

template<typename T>
void DLinkedList<T>::push_front(const T& val) {
	insert_before(begin(),val);
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
typename DLinkedList<T>::Iterator DLinkedList<T>::begin() {
	return Iterator(head->next);
}

template<typename T>
typename DLinkedList<T>::ConstIterator DLinkedList<T>::begin() const {
	return ConstIterator(head->next);
}

template<typename T>
typename DLinkedList<T>::Iterator DLinkedList<T>::end() {
	return Iterator(tail);
}

template<typename T>
typename DLinkedList<T>::ConstIterator DLinkedList<T>::end() const {
	return ConstIterator(tail);
}

template<typename T>
typename DLinkedList<T>::ReverseIterator DLinkedList<T>::rbegin() {
	return ReverseIterator(tail->prev);
}

template<typename T>
typename DLinkedList<T>::ConstReverseIterator DLinkedList<T>::rbegin() const {
	return ConstReverseIterator(tail->prev);
}

template<typename T>
typename DLinkedList<T>::ReverseIterator DLinkedList<T>::rend() {
	return ReverseIterator(head);
}

template<typename T>
typename DLinkedList<T>::ConstReverseIterator DLinkedList<T>::rend() const {
	return ConstReverseIterator(head);
}

template<typename T>
size_t DLinkedList<T>::size() const {return this->n;}

template<typename T>
typename DLinkedList<T>::Node* DLinkedList<T>::erase(Node* ptr) {
	if(ptr == head || ptr == tail || ptr == nullptr) throw std::invalid_argument("Out of bounds");
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
	return Iterator(erase(it.point));
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

template<typename T>
typename DLinkedList<T>::Iterator DLinkedList<T>::insert_in_order(const T& val) {
	Iterator it = begin();
	while(it) {
		if(it == end() || *it > val) {
			insert_before(it,val);
			break;
		}
		++it;
	}
	return --it;
}

template<typename T> template<class Predicate>
void DLinkedList<T>::remove_if(Predicate pred) {
	Iterator it = begin();
	while(it) {
		if(pred(*it)) it = erase(it);
		else if(it == end()) return;
		else ++it;
	}
}

}// end namespace mystl

#endif
