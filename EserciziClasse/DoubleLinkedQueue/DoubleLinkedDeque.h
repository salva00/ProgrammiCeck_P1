//
// Created by Salvatore Bramante on 09/05/21.
//

#ifndef DOUBLELINKEDQUEUE_DOUBLELINKEDDEQUE_H
#define DOUBLELINKEDQUEUE_DOUBLELINKEDDEQUE_H
#include "DoubleLinkedList.h"
template<typename T>
class DoubleLinkedDeque {
private:
    DoubleLinkedList<T> D;
    int n;
public:
    DoubleLinkedDeque();
    int size() const;
    bool empty() const;
    void insertFront( const T& e);
    void insertBack( const T& e);
    void removeFront();
    void removeBack();
};

template<typename T>
DoubleLinkedDeque<T>::DoubleLinkedDeque() :n(0){}

template<typename T>
int DoubleLinkedDeque<T>::size() const {
    return n;
}

template<typename T>
bool DoubleLinkedDeque<T>::empty() const {
    return n==0;
}

template<typename T>
void DoubleLinkedDeque<T>::insertFront(const T &e) {    //insert new first element
    D.addFront(e);
    n++;
}

template<typename T>
void DoubleLinkedDeque<T>::insertBack(const T &e) {     //insert new last element
    D.addBack(e);
    n++;
}

template<typename T>
void DoubleLinkedDeque<T>::removeFront() {          //remove the first element
    if (empty())
        throw std::runtime_error("Queue empty");
    D.removeFront();
    n--;
}

template<typename T>
void DoubleLinkedDeque<T>::removeBack() {               //remove the last element
    if (empty())
        throw std::runtime_error("Queue empty");
    D.removeBack();
    n--;
}


#endif //DOUBLELINKEDQUEUE_DOUBLELINKEDDEQUE_H
