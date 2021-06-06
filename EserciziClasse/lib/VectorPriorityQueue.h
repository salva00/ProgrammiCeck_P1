
#ifndef VECTOR_PRIORITY_QUEUE_H
#define VECTOR_PRIORITY_QUEUE_H

#include <vector>
#include "HeapSort.h"
// #include <iostream> //DEBUG

namespace mystl {

template<typename T>
class VPriorityQueue {
private:
	std::vector<T> elements;
public:
	VPriorityQueue();
	bool empty() const;
	size_t size() const;
	const T& front() const;
	void push(const T&);
	void pop();
	void clear();
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
bool VPriorityQueue<T>::empty() const {
	return elements.empty();
}

template<typename T>
size_t VPriorityQueue<T>::size() const {
	return elements.size();
}

template<typename T>
const T& VPriorityQueue<T>::front() const {
	if(empty()) throw std::runtime_error("Queue empty");
	return *elements.begin();
}

template<typename T>
void VPriorityQueue<T>::push(const T& val) {
	elements.push_back(val);
	mysort::build_heap(elements.begin(),elements.end());
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
