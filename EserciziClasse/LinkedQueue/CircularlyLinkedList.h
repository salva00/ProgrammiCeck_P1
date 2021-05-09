//
// Created by Salvatore Bramante on 09/05/21.
//

#ifndef LINKEDQUEUE_CIRCULARLYLINKEDLIST_H
#define LINKEDQUEUE_CIRCULARLYLINKEDLIST_H

#include <sstream>
#include "Cnode.h"
template<typename T>
class CircularlyLinkedList {
private:
    Cnode<T>* cursor;           //cursor
public:
    CircularlyLinkedList();
    ~CircularlyLinkedList();
    bool empty() const;
    const T& front() const;
    const T& back() const;
    void advance();             //advance cursor
    void add(const T& e);
    void remove();
    std::string toString();
};

template<typename T>
CircularlyLinkedList<T>::CircularlyLinkedList() : cursor{nullptr}{}

template<typename T>
CircularlyLinkedList<T>::~CircularlyLinkedList() { while (!empty()) remove();}

template<typename T>
bool CircularlyLinkedList<T>::empty() const {
    return cursor == nullptr;
}

template<typename T>
const T &CircularlyLinkedList<T>::front() const {       //element after cursor
    return cursor->next->element;
}

template<typename T>
const T &CircularlyLinkedList<T>::back() const {        //element at the cursor
    return cursor->element;
}

template<typename T>
void CircularlyLinkedList<T>::advance() {
    cursor = cursor->next;
}

template<typename T>
void CircularlyLinkedList<T>::add(const T &e) {         //add after cursor
    Cnode<T>* v = new Cnode<T>;                         //create a new node
    v->element = e;
    if (cursor == nullptr){                             //if list is empty
        v->next = v;                                    //v points itself
        cursor = v;                                     //cursor points to v
    }else{                                              //else
        v->next = cursor->next;                         //link in v after cursor
        cursor->next = v;
    }
}

template<typename T>
void CircularlyLinkedList<T>::remove() {                //remove node after cursor
    Cnode<T>* old = cursor->next;                       //the node being removed
    if (old==cursor)                                    //if the only node is the cursor
        cursor = nullptr;                               //set it to nullptr
    else                                                //else
        cursor->next = old->next;                       //link out the old node
    delete old;                                         //delete the old node
}

template<typename T>
std::string CircularlyLinkedList<T>::toString() {
    std::ostringstream out;
    Cnode<T>* u = cursor;
    out<<"Cursor -->";
    out<< u->element<< " --> ";
    u=u->next;
    while (u!=cursor){
        out<< u->element << " --> ";
        u = u->next;
    }
    out <<"Cursor";
    return out.str();
}

#endif //LINKEDQUEUE_CIRCULARLYLINKEDLIST_H
