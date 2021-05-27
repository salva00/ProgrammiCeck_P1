
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdexcept>

namespace mystl {

template <typename T>
class ArrayStack {
public:
	ArrayStack(int = DEF_CAPACITY);
	~ArrayStack();
	int size() const;
	// returns number of elements stored
	bool empty() const;
	// returns true if stack is empty
	const T& top() const;
	// returns element at the top
	void push(const T&);
	// inserts element at top
	const T& pop();
	// deletes and return element at the top
	void resize(int);
private:
	static const int DEF_CAPACITY{10};
	T* data;           //member data
	int capacity;   //stack capacity
	int index;          //index of top stack
};

template<typename T>
ArrayStack<T>::ArrayStack(int cap) : data(new T[cap]), capacity(cap), index(-1) {}

template<typename T>
ArrayStack<T>::~ArrayStack() {
	delete this->data;
}

template<typename T>
int ArrayStack<T>::size() const {
    return index+1;
}

template<typename T>
bool ArrayStack<T>::empty() const {
    return index<0;
}

template<typename T>
const T& ArrayStack<T>::top() const {
    if (empty()) throw std::runtime_error("Empty top of stack");
    return data[index];
}

template<typename T>
void ArrayStack<T>::push(const T& val) {
    if (this->index+1 == this->capacity) throw std::runtime_error("Stack full");
		data[++index] = val;
		return;
}

template<typename T>
const T& ArrayStack<T>::pop() {
    if (empty()) throw std::runtime_error("Stack empty");
    index--;
		return data[index+1];
}

template<typename T>
void ArrayStack<T>::resize(int size) {
	if(size > capacity) throw std::invalid_argument("New size cannot be larger than stack maximum capacity");
	else if(size < 0) throw std::invalid_argument("Size must be a positive integer");
	for(int i = index; i < size; i++) data[i]=0; //expansion
	index = size-1;
	return;
}

}// end namespace mystl
#endif
