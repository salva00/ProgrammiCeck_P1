
#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <iterator>
#include <stdexcept>

#define CONST true
#define NONCONST false

namespace mystl {
	template<typename T>
	class CLinkedList {
	private:
		class Node {
			friend class CLinkedList;
		private:
			T value;
			Node* next;
			Node(T, Node* = nullptr);
			~Node();
		};
		template<bool is_const = false> class GenericIterator;
	public:
		using Iterator = GenericIterator<NONCONST>;
		using ConstIterator = GenericIterator<CONST>;
	private:
		Node* cur;
		// like the back of the list
		size_t n;
		// number of nodes attached
	public:
		CLinkedList();
		// default constructor: create empty list
		CLinkedList(size_t, const T & = T());
		// create a list with #1 elements of value #2
		CLinkedList(const CLinkedList<T>&);
		// copy constructor
		CLinkedList<T>& operator=(const CLinkedList<T>&);
		// copy assignment
		~CLinkedList();
		// delete cursor node and all attached nodes
		bool empty() const;
		// return true if list is empty
		size_t size() const;
		// return number of elements stored in the list
		void push_front(const T&);
		// add element after cursor
		void push_back(const T&);
		// add element after cursor and advance list
		const T& front() const;
		// return value after cursor node
		const T& back() const;
		// return cursor node stored value
		void pop_front();
		// remove node after cursor
		void advance() const;
		// move cursor forward
		ConstIterator cbegin() const;
		// return iterator to begin
		ConstIterator cend() const;
		Iterator begin();
		// return iterator to begin
		Iterator end();
		// return iterator to end after #1 laps
		void clear();
		// remove every element in list
	};

	template<typename T>
	template<bool is_const>
	class CLinkedList<T>::GenericIterator {
		friend class CLinkedList<T>;
	private:
		explicit GenericIterator(typename CLinkedList<T>::Node*, bool);
		typename CLinkedList<T>::Node* point;
		bool bool_value = true;
	public:
		using iterator_category = std::bidirectional_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = typename std::conditional<is_const, const T, T>::type;
		using pointer = typename std::conditional<is_const, const T*, T*>::type;
		using reference = typename std::conditional<is_const, const T&, T&>::type;
		reference operator*() const;
		pointer operator->() const;
		GenericIterator<is_const>& operator++();
		GenericIterator<is_const> operator++(int);
		GenericIterator<is_const> operator+(size_t) const;
		GenericIterator<is_const>& operator--();
		GenericIterator<is_const> operator--(int);
		GenericIterator<is_const> operator-(size_t) const;
		bool operator==(const GenericIterator<is_const>&) const;
		bool operator!=(const GenericIterator<is_const>&) const;
		operator bool() const;
		operator GenericIterator<CONST>();
		// Non Const => Const
	};



	// Node //

	template<typename T>
	CLinkedList<T>::Node::Node(T v, Node* n) : value{ v }, next{ n } {}

	template<typename T>
	CLinkedList<T>::Node::~Node() {
		delete next;
		return;
	}


	// Iterator //

	template<typename T> template<bool is_const>
	CLinkedList<T>::GenericIterator<is_const>::GenericIterator(Node* p, bool bool_value) : point{ p }, bool_value{ bool_value } {}

	template<typename T> template<bool is_const>
	typename CLinkedList<T>::template GenericIterator<is_const>::reference CLinkedList<T>::GenericIterator<is_const>::operator*() const {
		return point->value;
	}

	template<typename T> template<bool is_const>
	typename CLinkedList<T>::template GenericIterator<is_const>::pointer CLinkedList<T>::GenericIterator<is_const>::operator->() const {
		return &point->value;
	}

	template<typename T> template<bool is_const>
	typename CLinkedList<T>::template GenericIterator<is_const>& CLinkedList<T>::GenericIterator<is_const>::operator++() {
		this->bool_value = true; // set start lap flag, used for operator==
		if (point) point = point->next;
		else throw std::runtime_error("Reached End");
		return *this;
	}

	template<typename T> template<bool is_const>
	typename CLinkedList<T>::template GenericIterator<is_const> CLinkedList<T>::GenericIterator<is_const>::operator++(int) {
		GenericIterator<is_const> temp = *this;
		this->operator++();
		return temp;
	}

	template<typename T> template<bool is_const>
	typename CLinkedList<T>::template GenericIterator<is_const> CLinkedList<T>::GenericIterator<is_const>::operator+(size_t amt) const {
		GenericIterator<is_const> res = *this;
		for (size_t i = 0; i < amt; ++i) ++res;
		return res;
	}

	template<typename T> template<bool is_const>
	typename CLinkedList<T>::template GenericIterator<is_const>& CLinkedList<T>::GenericIterator<is_const>::operator--() {
		if (point->prev) point = point->prev;
		else throw std::runtime_error("Reached End");
		return *this;
	}

	template<typename T> template<bool is_const>
	typename CLinkedList<T>::template GenericIterator<is_const> CLinkedList<T>::GenericIterator<is_const>::operator--(int) {
		GenericIterator<is_const> temp = *this;
		this->operator--();
		return temp;
	}

	template<typename T> template<bool is_const>
	typename CLinkedList<T>::template GenericIterator<is_const> CLinkedList<T>::GenericIterator<is_const>::operator-(size_t amt) const {
		GenericIterator<is_const> res = *this;
		for (size_t i = 0; i < amt; ++i) --res;
		return res;
	}

	template<typename T> template<bool is_const>
	bool CLinkedList<T>::GenericIterator<is_const>::operator==(const GenericIterator<is_const>& rhs) const {
		return ((this->point == rhs.point) && this->bool_value);	// if bool_value is false it means that iterator is at start, must advance at least one time with operator++
	}

	template<typename T> template<bool is_const>
	bool CLinkedList<T>::GenericIterator<is_const>::operator!=(const GenericIterator<is_const>& rhs) const {
		return this->point != rhs.point || !this->bool_value;
	}

	template<typename T> template<bool is_const>
	CLinkedList<T>::GenericIterator<is_const>::operator bool() const {
		return point != nullptr;
	}

	template<typename T> template<bool is_const>
	CLinkedList<T>::GenericIterator<is_const>::operator GenericIterator<CONST>() {
		return GenericIterator<CONST>(this->point);
	}

	/*
	template<typename T>
	CLinkedList<T>::Iterator::Iterator(Node* p, size_t s, const CLinkedList<T>* const list) : point{ p }, origin{ list }, lap{ s } {}

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
		if (point == origin->cur) ++lap;
		return *this;
	}

	template<typename T>
	typename CLinkedList<T>::Iterator CLinkedList<T>::Iterator::operator++(int) {
		Iterator temp = *this;
		point = point->next;
		if (point == origin->cur) ++lap;
		return temp;
	}

	template<typename T>
	bool CLinkedList<T>::Iterator::operator==(const Iterator& rhs) const {
		return (this->point == rhs.point) && (this->lap == rhs.lap) ||
			(this->point == nullptr && rhs.point == nullptr); //to make begin==end
	}

	template<typename T>
	bool CLinkedList<T>::Iterator::operator!=(const Iterator& rhs) const {
		return !(*this == rhs);
	}

	template<typename T>
	size_t CLinkedList<T>::Iterator::getLap() const { return lap; }

	template<typename T>
	CLinkedList<T>::Iterator::operator bool() const {
		return point != nullptr;
	}
	*/

	// CLinkedList //

	template<typename T>
	CLinkedList<T>::CLinkedList() : cur{ nullptr }, n{ 0 } {}

	template<typename T>
	CLinkedList<T>::CLinkedList(size_t amt, const T& val) : cur{ nullptr }, n{ 0 } {
		for (int i = 0; i < amt; i++) push_back(val);
	}

	template<typename T>
	CLinkedList<T>::CLinkedList(const CLinkedList<T>& list) : CLinkedList() {
		if (!list.empty()) {
			for (auto i = list.begin(); i != list.end(); ++i) {
				this->push_back(*i);
			}
		}
	}

	template<typename T>
	CLinkedList<T>& CLinkedList<T>::operator=(const CLinkedList<T>& rhs) {
		this->clear();
		CLinkedList<T> temp{ rhs };
		this->cur = temp.cur;
		this->n = temp.n;
		temp.cur = nullptr;
		return *this;
	}

	template<typename T>
	CLinkedList<T>::~CLinkedList() {
		if (!empty()) {
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
	bool CLinkedList<T>::empty() const { return cur == nullptr; }

	template<typename T>
	size_t CLinkedList<T>::size() const { return this->n; }

	template<typename T>
	void CLinkedList<T>::push_front(const T& val) {
		if (empty()) {
			cur = new Node(val, nullptr);
			cur->next = cur;
		}
		else cur->next = new Node(val, cur->next);
		++n;
		return;
	}

	template<typename T>
	void CLinkedList<T>::push_back(const T& val) {
		if (empty()) {
			cur = new Node(val, nullptr);
			cur->next = cur;
		}
		else cur->next = new Node(val, cur->next);
		++n;
		cur = cur->next;
		return;
	}

	template<typename T>
	const T& CLinkedList<T>::front() const {
		if (empty()) throw std::runtime_error("LinkedList is empty");
		return cur->next->value;
	}

	template<typename T>
	const T& CLinkedList<T>::back() const {
		if (empty()) throw std::runtime_error("LinkedList is empty");
		return cur->value;
	}

	template<typename T>
	void CLinkedList<T>::pop_front() {
		if (empty()) throw std::runtime_error("LinkedList is empty");
		if (n == 1) {
			cur->next = nullptr;
			delete cur;
			cur = nullptr;
		}
		else {
			Node* temp = cur->next;
			cur->next = cur->next->next;
			temp->next = nullptr;
			delete temp;
		}
		--n;
		return;
	}

	template<typename T>
	void CLinkedList<T>::advance() const {
		if (empty()) throw std::runtime_error("LinkedList is empty");
		cur = cur->next;
		return;
	}

	template<typename T>
	typename CLinkedList<T>::ConstIterator CLinkedList<T>::cbegin() const {
		return ConstIterator(cur->next, false);
	}

	template<typename T>
	typename CLinkedList<T>::ConstIterator CLinkedList<T>::cend() const {
		return ConstIterator(cur->next, true);
	}

	template<typename T>
	typename CLinkedList<T>::Iterator CLinkedList<T>::begin() {
		return Iterator(cur->next, false);
	}

	template<typename T>
	typename CLinkedList<T>::Iterator CLinkedList<T>::end() {
		return Iterator(cur->next, true);
	}

}// end namespace mystl

#endif
