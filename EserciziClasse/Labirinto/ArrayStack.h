//
// Created by Salvatore Bramante on 06/05/21.
//

#ifndef LABIRINTO_ARRAYSTACK_H
#define LABIRINTO_ARRAYSTACK_H
#ifndef ARRAYSTACK_ARRAYSTACK_H
#define ARRAYSTACK_ARRAYSTACK_H
#include <iostream>
#include <stdexcept>
template <typename E>
class ArrayStack {
private:
    static const int DEF_CAPACITY{30};
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
    const E& pop();
    const E& operator[](int i);
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
    s[t++]= e;
}

template<typename E>
const E& ArrayStack<E>::pop() {
    if (empty()) throw std::runtime_error("Stack full");
    t--;
}

template<typename E>
const E& ArrayStack<E>::operator[](int i) {
    return s[i];
}


#endif //ARRAYSTACK_ARRAYSTACK_H
#endif //LABIRINTO_ARRAYSTACK_H
