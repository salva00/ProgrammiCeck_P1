
#ifndef VECTOR_PRIORITY_QUEUE_H
#define VECTOR_PRIORITY_QUEUE_H

#include <vector>
#include <stdexcept>
#include "..\mysort\HeapSort.h"
// #include <iostream> //DEBUG

namespace mystl {

template<typename T>
class VPriorityQueue {
private:
	std::vector<T> elements;
public:
	VPriorityQueue();
	// default constructor
	VPriorityQueue(const std::initializer_list<T>&);
	// constructor a priority queue from #1 elements
	bool empty() const;
	// return true if empty
	size_t size() const;
	// return size
	const T& front() const;
	// access largest element
	void push(const T&);
	// enqueue element
	void pop();
	// remove largest element
	void clear();
	// clear queue

	/*DEBUG*/
	// void print();
};

/*DEBUG*/
// template<typename T>
// void VPriorityQueue<T>::print() {
// 	if(empty()) throw std::runtime_error("empty");
// 	for(auto i : elements) std::cout << i << ' ';
// 	std::cout << '\n';
// }

// VPriorityQueue //

template<typename T>
VPriorityQueue<T>::VPriorityQueue() : elements() {}

template<typename T>
VPriorityQueue<T>::VPriorityQueue(const std::initializer_list<T>& il) : elements(il) {
	mysort::build_heap(elements.begin(),elements.end());
}

template<typename T>
bool VPriorityQueue<T>::empty() const {
	return elements.empty();
}

template<typename T>
size_t VPriorityQueue<T>::size() const {
	return elements.size();
}

template<typename T>
const T& VPriorityQueue<T>::front() const {
	if(empty()) throw std::runtime_error("Priority queue is empty");
	return *elements.begin();
}

template<typename T>
void VPriorityQueue<T>::push(const T& val) {
	elements.push_back(val);
	mysort::push_heap(elements.begin(),elements.end());
	return;
}

template<typename T>
void VPriorityQueue<T>::pop() {
	if(empty()) throw std::runtime_error("Priority queue is empty");
	std::iter_swap(elements.begin(),elements.rbegin());
	elements.pop_back();
	mysort::heapify(elements.begin(),elements.end(),elements.begin());
	return;
}

template<typename T>
void VPriorityQueue<T>::clear() {
	elements.clear();
	return;
}

}// end namespace mystl

#endif









//
