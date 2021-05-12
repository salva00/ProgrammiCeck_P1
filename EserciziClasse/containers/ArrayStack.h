
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdexcept>

template <typename E>
class ArrayStack {
public:
	ArrayStack(int = DEF_CAPACITY);
	~ArrayStack();
	int size() const;
	bool empty() const;
	const E& top() const;
	void push(const E&);
	const E& pop();
	void resize(int);
// private:
	static const int DEF_CAPACITY{10};
	E* s;           //member data
	int capacity;   //stack capacity
	int t;          //index of top stack
};

template<typename E>
ArrayStack<E>::ArrayStack(int cap) : s(new E[cap]), capacity(cap), t(-1) {}

template<typename E>
ArrayStack<E>::~ArrayStack() {
	delete this->s;
}

template<typename E>
int ArrayStack<E>::size() const {
    return t+1;
}

template<typename E>
bool ArrayStack<E>::empty() const {
    return t<0;
}

template<typename E>
const E& ArrayStack<E>::top() const {
    if (empty()) throw std::runtime_error("Empty top of stack");
    return s[t];
}

template<typename E>
void ArrayStack<E>::push(const E& e) {
    if (this->t+1 == this->capacity) throw std::runtime_error("Stack full");
		s[++t] = e;
		return;
}

template<typename E>
const E& ArrayStack<E>::pop() {
    if (empty()) throw std::runtime_error("Stack empty");
    t--;
		return s[t+1];
}

template<typename E>
void ArrayStack<E>::resize(int size) {
	if(size > capacity) throw std::invalid_argument("New size cannot be larger than stack maximum capacity");
	else if(size < 0) throw std::invalid_argument("Size must be a positive integer");
	for(int i = t; i < size; i++) s[i]=0; //expansion
	t = size-1;
	return;
}

#endif
