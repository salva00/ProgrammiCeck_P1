
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include<stdexcept>

namespace mystl {

template<typename T>
class ArrayQueue {
private:
	T* elems;
	size_t tail{0};
	// tail of queue. new elements will be added here
	size_t head{0};
	// head of the queue. elements will be popped here
	size_t maxsize;
	// max elements queue may contain
	size_t n{0};
	// amount of elements stored
public:
	ArrayQueue(size_t = 16);
	// constructs a queue that may contain maximum #1 elements
	~ArrayQueue();
	// deallocates elems
	const T& front();
	// access first element
	const T& back();
	// access last element
	bool empty();
	// returns true if empty
	size_t size();
	// returns amount of elements stored
	void enqueue(const T&);
	// add elements at the end of queue (tail)
	void dequeue();
	// removes element at the head of the queue
};



// ArrayQueue //

template<typename T>
ArrayQueue<T>::ArrayQueue(size_t s) :
	elems{new T[s]}, maxsize{s} {};

template<typename T>
ArrayQueue<T>::~ArrayQueue() {
	delete elems;
}

template<typename T>
const T& ArrayQueue<T>::front() {
	if(n == 0) throw std::runtime_error("Queue empty");
	return elems[head];
}

template<typename T>
const T& ArrayQueue<T>::back() {
	if(n == 0) throw std::runtime_error("Queue empty");
	return elems[tail-1];
}

template<typename T>
bool ArrayQueue<T>::empty() {
	return n == 0;
}

template<typename T>
size_t ArrayQueue<T>::size() {
	return n;
}

template<typename T>
void ArrayQueue<T>::enqueue(const T& val) {
	if(n == maxsize) throw std::runtime_error("Queue full");
	elems[tail] = val;
	tail = (tail + 1) % maxsize;
	++n;
	return;
}

template<typename T>
void ArrayQueue<T>::dequeue() {
	if(n == 0) throw std::runtime_error("Queue empty");
	head = (head + 1) % maxsize;
	--n;
	return;
}


} // end namespace mystl

#endif







//
