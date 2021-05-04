//
// Created by Salvatore Bramante on 03/05/21.
//

#include "StringLinkedList.h"

StringLinkedList::StringLinkedList() : head(nullptr){}

StringLinkedList::~StringLinkedList() {
    while (!empty()){
        removeFront();
    }
}

bool StringLinkedList::empty() const {
    return head== nullptr;
}

const std::string &StringLinkedList::front() const {
    return head->elem;
}

void StringLinkedList::addFront(const std::string &e) { // add to front of list
    StringNode* v = new StringNode;                     // create new node
    v-> elem = e;                                       // store data
    v->next = head;                                     // head now follows v
    head = v;                                           //v is the head

}

void StringLinkedList::removeFront() {                      //remove from item
    if (empty()){
        throw std::runtime_error{"List is Empty"};
    }
    StringNode* old = head;                                 // save current head
    head = head->next;                                       // skip over old head
    delete old;                                             // delete the old head
}
