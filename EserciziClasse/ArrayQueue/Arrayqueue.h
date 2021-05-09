//
// Created by Salvatore Bramante on 09/05/21.
//

#ifndef ARRAYQUEUE_ARRAYQUEUE_H
#define ARRAYQUEUE_ARRAYQUEUE_H

#include <vector>

template <typename T>
class Arrayqueue {
private:
    int N;
    int head;
    int tail;
    T* queue;
public:
    Arrayqueue(int n);
    int size() const;
    bool empty() const;
    void enqueue(T);
    void dequeue();
    const T front() const;
    bool full()const;

};


template<typename T>
Arrayqueue<T>::Arrayqueue(int n) : N(n), head(0),tail(0), queue(new T[n]){}

template<typename T>
int Arrayqueue<T>::size() const {
    return N;
}

template<typename T>
bool Arrayqueue<T>::empty() const {
    return N==0;
}

//overflow : head = tail + 1%N
//underflow: head=tail

template<typename T>
void Arrayqueue<T>::enqueue(T e) {
    if (full()){
        throw std::runtime_error("Stack full");
    }
    queue[tail] = e;
    //head += 1%N;
    tail += 1%N;
    N++;

}

template<typename T>
void Arrayqueue<T>::dequeue() {
    if (empty()){
        throw std::runtime_error("Stack empty");
    }
    head+=1%N;
    N--;
}

template<typename T>
const T Arrayqueue<T>::front() const {
    if (empty()){
        throw std::runtime_error("Stack empty");
    }
    return queue[head];
}

template<typename T>
bool Arrayqueue<T>::full() const {
    return  head == tail + 1%N;
}


#endif //ARRAYQUEUE_ARRAYQUEUE_H
