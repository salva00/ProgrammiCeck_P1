
#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "CircularLinkedList.h"

namespace mystl {

template<typename T>
class LinkedQueue {
private:
	CLinkedList<T> elems;
public:
	LinkedQueue();
	// default constructor
	LinkedQueue(size_t, const T&);
	// create a queue with #1 elements of value #2
	bool empty() const;
	// returns true if queue is empty
	size_t size() const;
	// returns number of elements stored in the queue
	const T& front() const;
	// returns first element
	const T& back() const;
	// returns newest element
	void enqueue(const T&);
	// adds element at the queue
	void dequeue();
	// removes element from the queue
	void clear();
	// removes every element in queue
};



// LinkedQueue //

template<typename T>
LinkedQueue<T>::LinkedQueue() : elems{} {}

template<typename T>
LinkedQueue<T>::LinkedQueue(size_t amt, const T& val) : elems{amt,val} {}

template<typename T>
bool LinkedQueue<T>::empty() const {return elems.empty();}

template<typename T>
size_t LinkedQueue<T>::size() const {return elems.size();}

template<typename T>
const T& LinkedQueue<T>::front() const {return elems.front();}

template<typename T>
const T& LinkedQueue<T>::back() const {return elems.back();}

template<typename T>
void LinkedQueue<T>::clear() {
	elems.clear();
	return;
}

template<typename T>
void LinkedQueue<T>::enqueue(const T& val) {
	elems.push_back(val);
	return;
}

template<typename T>
void LinkedQueue<T>::dequeue() {
	elems.pop_front();
	return;
}

}//end namespace mystl

#endif








//
