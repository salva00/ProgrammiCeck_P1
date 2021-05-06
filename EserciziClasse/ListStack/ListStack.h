//
// Created by Salvatore Bramante on 06/05/21.
//

#ifndef LISTSTACK_LISTSTACK_H
#define LISTSTACK_LISTSTACK_H
#include <iostream>
#include <stdexcept>
#include "LinkedList.h"
template <typename NODETYPE>
class ListStack {
private:
    LinkedList<NODETYPE> s;           //member data
    int n;   //stack size
public:
    ListStack();
    ~ListStack();
    int size() const;
    bool empty() const;
    const NODETYPE& top() const;
    void push(const NODETYPE&);
    void pop();
};

template<typename NODETYPE>
ListStack<NODETYPE>::ListStack() : s(), n(0) {}

template<typename NODETYPE>
ListStack<NODETYPE>::~ListStack() {}

template<typename NODETYPE>
int ListStack<NODETYPE>::size() const {
    return n;
}

template<typename NODETYPE>
bool ListStack<NODETYPE>::empty() const {
    return n==0;
}

template<typename NODETYPE>
const NODETYPE &ListStack<NODETYPE>::top() const {
    if (empty()) throw std::runtime_error("Empty top of stack");
    return s.front();
}

template<typename NODETYPE>
void ListStack<NODETYPE>::push(const NODETYPE &e) {
    n++;
    s.addFront(e);
}

template<typename NODETYPE>
void ListStack<NODETYPE>::pop() {
    if (empty()) throw std::runtime_error("Empty top of stack");
    n--;
    s.removeFront();
}

#endif