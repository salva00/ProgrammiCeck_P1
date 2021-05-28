
#ifndef ARRAYSTACK_ARRAYSTACK_H
#define ARRAYSTACK_ARRAYSTACK_H
#include <iostream>
#include <stdexcept>
template <typename E>
class ArrayStack {
private:
    static const int DEF_CAPACITY{10};
    E* s;           //member data
    int capacity;   //stack capacity
    int t;          //index of top stack
public:
    ArrayStack(int = DEF_CAPACITY);
    ~ArrayStack();
    int size() const;
    bool empty() const;
    const E& top() const;
    void push(const E&);
    void pop();
};

template<typename E>
ArrayStack<E>::ArrayStack(int cap) : s(new E[cap]), capacity(cap), t(-1) {}

template<typename E>
ArrayStack<E>::~ArrayStack() {

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
const E &ArrayStack<E>::top() const {
    if (empty()) throw std::runtime_error("Empty top of stack");
    return s[t];
}

template<typename E>
void ArrayStack<E>::push(const E &e) {
    if (empty()) throw std::runtime_error("Stack full");
    s[t++]= e;
}

template<typename E>
void ArrayStack<E>::pop() {
    if (empty()) throw std::runtime_error("Stack full");
    t--;
}


#endif //ARRAYSTACK_ARRAYSTACK_H
