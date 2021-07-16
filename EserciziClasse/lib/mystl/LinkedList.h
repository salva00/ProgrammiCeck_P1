#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iterator>
#include <stdexcept>
#include <type_traits>

#define CONST true
#define NONCONST false

namespace mystl {

	template<typename T>
	class LinkedList {
	private:
		class Node {
			friend class LinkedList<T>;
		private:
			T value;
			Node* next;
			Node(T, Node* = nullptr);
			~Node();
		};
		template<bool is_const> class GenericIterator;
	public:
		using Iterator = GenericIterator<NONCONST>;
		using ConstIterator = GenericIterator<CONST>;
	private:
		Node* head;
		// first node with content
		size_t n;
		// number of nodes attached
	public:
		LinkedList();
		// default constructor: create empty list
		LinkedList(size_t, const T&);
		// create a list with #1 elements of value #2
		LinkedList(const LinkedList&);
		// copy constructor
		explicit LinkedList(const std::initializer_list<T>&);
		// construct a list from initalizer list
		LinkedList& operator=(const LinkedList&);
		// copy assignment
		~LinkedList();
		// delete all nodes
		bool empty() const;
		// return true if list is empty
		const T& front() const;
		// return first element
		void push_front(const T&);
		// add element at the beginning
		void pop_front();
		// delete first element
		size_t size() const;
		// return number of elements stored
		ConstIterator cbegin() const;
		// return const iterator to first element
		ConstIterator begin() const;
		Iterator begin();
		// return iterator to first element
		ConstIterator cend() const;
		// return const iterator to last element
		ConstIterator end() const;
		Iterator end();
		// return iterator to last element
		void erase_after(const Iterator&);
		// erase element AFTER iterator
		void insert_after(const Iterator&, const T&);
		// insert element after iterator
		void clear();
		// list empty
		Iterator insert_in_order(const T&);
		// insert #1 in an ordered list, keeping it ordered
		template<class Predicate> void remove_if(Predicate);
		// remove all elements for which predicate returns true
	};

	template<typename T>
	template<bool is_const>
	class LinkedList<T>::GenericIterator {
		friend class LinkedList<T>;
	private:
		explicit GenericIterator(typename LinkedList<T>::Node*);
		typename LinkedList<T>::Node* point;
	public:
		//using iterator_category = std::bidirectional_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = typename std::conditional<is_const, const T, T>::type;
		using pointer = typename std::conditional<is_const, const T*, T*>::type;
		using reference = typename std::conditional<is_const, const T&, T&>::type;
		reference operator*() const;
		pointer operator->() const;
		GenericIterator<is_const>& operator++();
		GenericIterator<is_const> operator++(int);
		GenericIterator<is_const> operator+(size_t) const;
		bool operator==(const GenericIterator<is_const>&) const;
		bool operator!=(const GenericIterator<is_const>&) const;
		operator bool() const;
		operator GenericIterator<CONST>();
		// Non Const => Const
	};


	// Node //

	template<typename T>
	LinkedList<T>::Node::Node(T v, Node* n) : value{v}, next{n} {}

	template<typename T>
	LinkedList<T>::Node::~Node() {
		if(next) delete next;
		return;
	}

	// Iterator //

	template<typename T> template<bool is_const>
	LinkedList<T>::GenericIterator<is_const>::GenericIterator(Node* p) : point{p} {}

	template<typename T> template<bool is_const>
	typename LinkedList<T>::template GenericIterator<is_const>::reference LinkedList<T>::GenericIterator<is_const>::operator*() const {
		return point->value;
	}

	template<typename T> template<bool is_const>
	typename LinkedList<T>::template GenericIterator<is_const>::pointer LinkedList<T>::GenericIterator<is_const>::operator->() const {
		return &point->value;
	}

	template<typename T> template<bool is_const>
	typename LinkedList<T>::template GenericIterator<is_const>& LinkedList<T>::GenericIterator<is_const>::operator++() {
		if(point) point = point->next;
		else throw std::runtime_error("Reached End");
		return *this;
	}

	template<typename T> template<bool is_const>
	typename LinkedList<T>::template GenericIterator<is_const> LinkedList<T>::GenericIterator<is_const>::operator++(int) {
		GenericIterator<is_const> temp = *this;
		this->operator++();
		return temp;
	}

	template<typename T> template<bool is_const>
	typename LinkedList<T>::template GenericIterator<is_const> LinkedList<T>::GenericIterator<is_const>::operator+(size_t amt) const {
		GenericIterator<is_const> res = *this;
		for(size_t i = 0; i < amt; ++i) ++res;
		return res;
	}

	template<typename T> template<bool is_const>
	bool LinkedList<T>::GenericIterator<is_const>::operator==(const GenericIterator<is_const>& rhs) const {
		return this->point == rhs.point;
	}

	template<typename T> template<bool is_const>
	bool LinkedList<T>::GenericIterator<is_const>::operator!=(const GenericIterator<is_const>& rhs) const {
		return this->point != rhs.point;
	}

	template<typename T> template<bool is_const>
	LinkedList<T>::GenericIterator<is_const>::operator bool() const {
		return bool(point);
	}

	template<typename T> template<bool is_const>
	LinkedList<T>::GenericIterator<is_const>::operator GenericIterator<CONST>() {
		return GenericIterator<CONST>(this->point);
	}

	// Linked List //

	template<typename T>
	LinkedList<T>::LinkedList() : head{nullptr}, n{0} {}

	template<typename T>
	LinkedList<T>::LinkedList(size_t amount, const T& val) : head{nullptr}, n{amount} {
		for(size_t i = 0; i < amount; i++) push_front(val);
	}

	template<typename T>
	LinkedList<T>::LinkedList(const LinkedList& rhs) : head{nullptr}, n{0} {
		if(!rhs.empty()) {
			this->head = new Node(rhs.head->value);
			for(Node* i = head, *j = rhs.head; j->next != nullptr; j = j->next, i = i->next) {
				i->next = new Node(j->next->value);
			}
			this->n = rhs.size();
		}
	}

	template<typename T>
	LinkedList<T>::LinkedList(const std::initializer_list<T>& il) : head{nullptr}, n{il.size()} {
		auto ptr = il.end();
		while (ptr-- != il.begin()) {
			push_front(*ptr);
		}
	}

	template<typename T>
	LinkedList<T>& LinkedList<T>::operator=(const LinkedList& rhs) {
		if (!empty()) clear();
		LinkedList<T> temp{rhs};
		this->head = temp.head;
		this->n = temp.n;
		temp.head = nullptr;
		return *this;
	}

	template<typename T>
	LinkedList<T>::~LinkedList() {
		if(head) delete head;
		return;
	}

	template<typename T>
	bool LinkedList<T>::empty() const {
		return this->head == nullptr;
	}

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
	size_t LinkedList<T>::size() const {
		return this->n;
	}

	template<typename T>
	typename LinkedList<T>::ConstIterator LinkedList<T>::cbegin() const {
		return ConstIterator(head);
	}

	template<typename T>
	typename LinkedList<T>::ConstIterator LinkedList<T>::cend() const {
		return ConstIterator(nullptr);
	}

	template<typename T>
	typename LinkedList<T>::ConstIterator LinkedList<T>::begin() const {
		return ConstIterator(head);
	}

	template<typename T>
	typename LinkedList<T>::Iterator LinkedList<T>::begin() {
		return Iterator(head);
	}

	template<typename T>
	typename LinkedList<T>::ConstIterator LinkedList<T>::end() const {
		return ConstIterator(nullptr);
	}

	template<typename T>
	typename LinkedList<T>::Iterator LinkedList<T>::end() {
		return Iterator(nullptr);
	}

	template<typename T>
	void LinkedList<T>::erase_after(const Iterator& it) {
		Node* temp = it.point->next;
		if(temp == nullptr) throw std::invalid_argument("Index out of bounds");
		it.point->next = temp->next;
		temp->next = nullptr;
		delete temp;
		--n;
		return;
	}

	template<typename T>
	void LinkedList<T>::insert_after(const Iterator& it, const T& val) {
		if(it.point == nullptr) throw std::invalid_argument("Index out of bounds");
		it.point->next = new Node(val, it.point->next);
		return;
		++n;
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

	template<typename T>
	typename LinkedList<T>::Iterator LinkedList<T>::insert_in_order(const T& val) {
		Iterator prev = begin();
		if(empty() || val < *prev) {
			push_front(val);
			return begin();
		}
		for(Iterator next = prev; prev != end(); ++prev) {
			++next;
			if (next == end() || val < *next) {
				insert_after(prev, val);
				break;
			}
		}
		return ++prev;
	}

	template<typename T> template<class Predicate>
	void LinkedList<T>::remove_if(Predicate pred) {
		if(empty()) return;
		Iterator prev = begin();
		while(prev != end() && pred(*prev)) {
			++prev;
			pop_front();
		}
		for(Iterator next = prev; prev != end(); ++prev) {
			++next;
			while(next != end() && pred(*next)) {
				++next;
				erase_after(prev);
			}
		}
		return;
	}

}//end namespace mystl

#endif
