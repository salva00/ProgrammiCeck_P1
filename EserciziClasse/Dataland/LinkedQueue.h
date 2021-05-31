//
// Created by Salvatore Bramante on 31/05/21.
//

#ifndef DATALAND_LINKEDQUEUE_H
#define DATALAND_LINKEDQUEUE_H
#include "CircularLinkedList.h"
template<typename T>
class LinkedQueue {
private:
    CLinkedList<T> elems;
public:
    LinkedQueue();
    // default constructor
    LinkedQueue(size_t, const T&);
    // create a queue with #1 elements of value #2
    bool empty() const;
    // returns true if queue is empty
    size_t size() const;
    // returns number of elements stored in the queue
    T& front() ;
    // returns first element
    const T& back() const;
    // returns newest element
    void enqueue(const T&);
    // adds element at the queue
    void dequeue();
    // removes element from the queue
};



// LinkedQueue //

template<typename T>
LinkedQueue<T>::LinkedQueue() : elems{} {}

template<typename T>
LinkedQueue<T>::LinkedQueue(size_t amt, const T& val) : elems{amt,val} {}

template<typename T>
bool LinkedQueue<T>::empty() const {return elems.empty();}

template<typename T>
size_t LinkedQueue<T>::size() const {return elems.size();}

template<typename T>
T& LinkedQueue<T>::front()  {return elems.front();}

template<typename T>
const T& LinkedQueue<T>::back() const {return elems.back();}

template<typename T>
void LinkedQueue<T>::enqueue(const T& val) {
    elems.push_back(val);
}

template<typename T>
void LinkedQueue<T>::dequeue() {
    elems.pop_front();
}


#endif //DATALAND_LINKEDQUEUE_H
