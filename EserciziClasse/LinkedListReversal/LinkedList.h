//
// Created by Salvatore Bramante on 05/05/21.
//

#ifndef LINKEDLISTREVERSAL_LINKEDLIST_H
#define LINKEDLISTREVERSAL_LINKEDLIST_H

#include <sstream>
#include "Node.h"

template<typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList();
    ~LinkedList();
    bool empty() const;
    const T& front() const;
    void addFront(const T& e);
    void removeFront();
    std::string toString();
};

template<typename T>
LinkedList<T>::LinkedList():head{nullptr} {}

template<typename T>
LinkedList<T>::~LinkedList(){ while (!empty()) removeFront();}

template<typename T>
bool LinkedList<T>::empty() const {
    return head == nullptr;
}

template<typename T>
const T &LinkedList<T>::front() const {
    return head->element;
}

template<typename T>
void LinkedList<T>::addFront(const T &e) {
    Node<T>* v = new Node<T>;                     // create new node
    v-> element = e;                                       // store data
    v->next = head;                                     // head now follows v
    head = v;                                           //v is the head
}

template<typename T>
void LinkedList<T>::removeFront() {
    if (empty()){
        throw std::runtime_error{"List is Empty"};
    }
    Node<T>* old = head;                                 // save current head
    head = head->next;                                       // skip over old head
    delete old;
}

template<typename T>
std::string LinkedList<T>::toString() {
    Node<T>* p = head;
    std::ostringstream output;
    std::cout<<"List --> ";
    while (p != nullptr){
        std::cout<< p->element<<" --> ";
        p=p->next;
    }
    return output.str();
}




#endif //LINKEDLISTREVERSAL_LINKEDLIST_H
