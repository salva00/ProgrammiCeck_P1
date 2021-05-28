
#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "LinkedList.h"

namespace mystl {

template<typename T>
class LinkedStack {
private:
	LinkedList<T> elems;
public:
	LinkedStack();
	// default constructor
	LinkedStack(size_t ,const T&);
	// creates a stack with #1 elements of value #2
	bool empty();
	// returns true if empty
	size_t size();
	// returns number of elements stored
	void pop();
	// removes last element
	void push(const T&);
	// adds element at the top
	const T& top();
	// returns top element
};

template<typename T>
LinkedStack<T>::LinkedStack() : elems{} {};

template<typename T>
LinkedStack<T>::LinkedStack(size_t amt, const T& val) : elems{amt,val} {};

template<typename T>
bool LinkedStack<T>::empty() {return elems.empty();}

template<typename T>
size_t LinkedStack<T>::size() {return elems.size();}

template<typename T>
void LinkedStack<T>::pop() {
	elems.pop_front();
	return;
}

template<typename T>
void LinkedStack<T>::push(const T& val) {
	elems.push_front(val);
	return;
}

template<typename T>
const T& LinkedStack<T>::top() {return elems.front();}

}//end namespace mystl

#endif
