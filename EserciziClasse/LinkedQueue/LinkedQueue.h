//
// Created by Salvatore Bramante on 09/05/21.
//

#ifndef LINKEDQUEUE_LINKEDQUEUE_H
#define LINKEDQUEUE_LINKEDQUEUE_H
#include <stdexcept>
#include <iostream>
#include "CircularlyLinkedList.h"
template <typename T>
class LinkedQueue {
private:
    CircularlyLinkedList<T> C;      // circular list of elementd
    int n;                          // number of elements
public:
    LinkedQueue();                  // costructor
    int size() const;               // number of items in the queue
    bool empty() const;             // Is the queue empty?
    const T& front();               // returns front element
    void enqueue(const T& e);       // enqueue element at rear
    void dequeue();                 // dequeue element at front
};

template<typename T>
LinkedQueue<T>::LinkedQueue() : C(),n{0}{}

template<typename T>
bool LinkedQueue<T>::empty() const {
    return n==0;
}

template<typename T>
int LinkedQueue<T>::size() const {
    return n;
}

template<typename T>
const T &LinkedQueue<T>::front() {
    if (empty())
        throw std::runtime_error("front of empty queue");
    return C.front();           // list front is queue front
}

template<typename T>
void LinkedQueue<T>::enqueue(const T &e) {
    C.add(e);   //insert after cursor
    C.advance();    //advance cursor
    n++;
}

template<typename T>
void LinkedQueue<T>::dequeue() {
    if (empty())
        throw std::runtime_error("front of empty queue");
    C.remove();             //remove from list front
    n--;
}


#endif //LINKEDQUEUE_LINKEDQUEUE_H
