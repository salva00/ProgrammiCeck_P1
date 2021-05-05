//
// Created by Salvatore Bramante on 05/05/21.
//

#ifndef DOUBLELINKEDLIST_LINKEDLIST_H
#define DOUBLELINKEDLIST_LINKEDLIST_H
#include <stdexcept>
#include "Dnode.h"
template <typename T>
class DoubleLinkedList {
private:
    Dnode<T>* header;
    Dnode<T>* trailer;
protected:
    void add(Dnode<T>* v, const T& e);
    void remove(Dnode<T>* v);

public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    bool empty()const;
    const T& front() const;
    const T& back() const;
    void addFront(const T&);
    void addBack(const T&);
    void removeFront();
    void removeBack();
    void addOrder(const T&);
    std::string toString();

};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
    header= new Dnode<T>;
    trailer= new Dnode<T>;
    header->next=trailer;
    header->prev= nullptr;
    trailer->prev=header;
    trailer->next= nullptr;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    while (!empty()) removeFront();
    delete header;
    delete trailer;
}

template<typename T>
bool DoubleLinkedList<T>::empty() const {
    return header->next==trailer;
}

template<typename T>
const T &DoubleLinkedList<T>::front() const {
    return header->next->element;
}

template<typename T>
const T &DoubleLinkedList<T>::back() const {
    return trailer->prev->element;
}

template<typename T>
void DoubleLinkedList<T>::add(Dnode<T>* v,const T &e) {
    Dnode<T>* u = new Dnode<T>;
    u->element= e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next=u;
    v->prev=u;
}

template<typename T>
void DoubleLinkedList<T>::addFront(const T &e) {
    add(front(),e);
}

template<typename T>
void DoubleLinkedList<T>::addBack(const T &e) {
    add(back(),e);
}

template<typename T>
void DoubleLinkedList<T>::remove(Dnode<T>* v) {
    if(empty()){
        throw std::invalid_argument("list must be not empty");
    }
    Dnode<T>* u = v->prev;
    Dnode<T>* w = v->next;
    u->prev = w;
    w->prev= u;
    delete v;
}

template<typename T>
void DoubleLinkedList<T>::removeFront() {
    remove(front());
}

template<typename T>
void DoubleLinkedList<T>::removeBack() {
    remove(back());
}

template<typename T>
std::string DoubleLinkedList<T>::toString() {
    std::ostringstream out;
    Dnode<T>* u = header->next;
    out<<"<-- Header\n";
    while (u!=trailer){
        out<< u->element;
        u=u->next;
    }
    out<<"\nTrailer -->";
    return out.str();
}

template<typename T>
void DoubleLinkedList<T>::addOrder(const T& e) {
    Dnode<T>* u = header->next;
    while (u!=trailer){
        if (e< u->element)
            break;
        u=u->next;
    }
    add(u,e);
}


#endif //DOUBLELINKEDLIST_LINKEDLIST_H
