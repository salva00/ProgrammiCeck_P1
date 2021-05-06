//
// Created by Salvatore Bramante on 06/05/21.
//

#ifndef LISTSTACK_LINKEDLIST_H
#define LISTSTACK_LINKEDLIST_H


#include "Node.h"
#include <stdexcept>

template<typename NODETYPE>
class LinkedList {
private:
    Node<NODETYPE>* head;
public:
    LinkedList();
    ~LinkedList();
    bool empty();
    const NODETYPE& front() const;          //return front element
    void addFront(const NODETYPE& e);
    void removeFront();
    NODETYPE& operator[](int);
    int size();
};

template<typename NODETYPE>
LinkedList<NODETYPE>::LinkedList() : head(nullptr) {}

template<typename NODETYPE>
LinkedList<NODETYPE>::~LinkedList() {
    while (!empty()) removeFront();
}

template<typename NODETYPE>
bool LinkedList<NODETYPE>::empty() {
    return head == nullptr;
}

template<typename NODETYPE>
const NODETYPE& LinkedList<NODETYPE>::front() const {
    return head->element;
}

template<typename NODETYPE>
void LinkedList<NODETYPE>::addFront(const NODETYPE& e) {
    Node<NODETYPE>* p = new Node<NODETYPE>;
    p->element = e;
    p->next = head;
    head = p;
}

template<typename NODETYPE>
void LinkedList<NODETYPE>::removeFront() {
    if (empty()) {
        throw std::invalid_argument("List is empty");
    }
    Node<NODETYPE>* old = head;
    head = old->next;
    delete old;
}
template <typename NODETYPE>
int LinkedList<NODETYPE>::size() {
    int i{ 0 };
    Node<NODETYPE>* pSize = head;
    while (pSize != nullptr) {
        i++;
        pSize = pSize->next;
    }
    return i;
}

template<typename NODETYPE>
NODETYPE& LinkedList<NODETYPE>::operator[](int pos) {
    if (pos >= size() || pos < 0) {
        throw std::invalid_argument("Size not correct");
    }
    Node<NODETYPE>* pPos = head;
    int i{ 0 };
    while (i != pos) {
        pPos = pPos->next;
        i++;
    }
    return pPos->element;
}

#endif //LISTSTACK_LINKEDLIST_H
