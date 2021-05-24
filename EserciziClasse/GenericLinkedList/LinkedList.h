//
// Created by Salvatore Bramante on 04/05/21.
//

#ifndef GENERICLINKEDLIST_LINKEDLIST_H
#define GENERICLINKEDLIST_LINKEDLIST_H

#include "Node.h"
#include <stdexcept>
#include <iostream>
template<typename NODETYPE>
class LinkedList {
private:
    Node<NODETYPE>* head;
public:
    LinkedList();
    LinkedList(const LinkedList<NODETYPE> &list);
    LinkedList<NODETYPE>& operator=(const LinkedList<NODETYPE> &list);
    ~LinkedList();
    bool empty() const;
    const NODETYPE& front() const;          //return front element
    void addFront(const NODETYPE& e);
    void removeFront();
    NODETYPE& operator[](int);
    int size() const;
};

template<typename NODETYPE>
LinkedList<NODETYPE>::LinkedList() : head(nullptr) {}

template<typename NODETYPE>
LinkedList<NODETYPE>::~LinkedList() {
    while (!empty()) removeFront();
}

template<typename NODETYPE>
bool LinkedList<NODETYPE>::empty() const {
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
int LinkedList<NODETYPE>::size() const {
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

template<typename NODETYPE>
LinkedList<NODETYPE>::LinkedList(const LinkedList<NODETYPE> &list) : head{nullptr} {
	*this = list;
}

template<typename NODETYPE>
LinkedList<NODETYPE>& LinkedList<NODETYPE>::operator=(const LinkedList<NODETYPE> &list) {
	if(!empty()) this->~LinkedList();
	head = nullptr;
	if(list.head == nullptr){
			this->head = nullptr;
			return *this;
	} else {
		this->head = new Node<NODETYPE>;
		this->head->element = list.head->element;
		for(Node<NODETYPE> *i{head}, *j{list.head}; j->next != nullptr; j = j->next, i = i->next) {
			i->next = new Node<NODETYPE>;
			i->next->element = j->next->element;
			i->next->next = nullptr;
		}
	}
	return *this;
}


#endif //GENERICLINKEDLIST_LINKEDLIST_H
