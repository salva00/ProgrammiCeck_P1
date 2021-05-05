//
// Created by Salvatore Bramante on 04/05/21.
//

#ifndef GENERICLINKEDLIST_LINKEDLIST_H
#define GENERICLINKEDLIST_LINKEDLIST_H

#include "Node.h"
#include <stdexcept>

template<typename NODETYPE>
class LinkedList{
private:
    Node<NODETYPE>* head;
public:
    LinkedList();
    ~LinkedList();
    bool empty();
    const NODETYPE& front() const;          //return front element
    void addFront(const NODETYPE& e);
    void removeFront();
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
const NODETYPE &LinkedList<NODETYPE>::front() const {
    return head->element;
}

template<typename NODETYPE>
void LinkedList<NODETYPE>::addFront(const NODETYPE &e) {
    Node<NODETYPE>* p = new Node<NODETYPE>;
    p->element = e;
    p->next=head;
    head=p;
}

template<typename NODETYPE>
void LinkedList<NODETYPE>::removeFront() {
    if(head== nullptr){
        throw std::invalid_argument("List is empty");
    }
    Node<NODETYPE>* old = head;
    head = old->next;
    delete old;
}



#endif //GENERICLINKEDLIST_LINKEDLIST_H
