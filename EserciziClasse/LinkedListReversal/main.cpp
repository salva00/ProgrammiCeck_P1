#include <iostream>
#include "LinkedList.h"

template<typename T>
void reverseList(LinkedList<T>& L) {
    LinkedList<T> list;
    while (!L.empty()){
        T e = L.front();
        L.removeFront();
        list.addFront(e);
    }
    while (!list.empty()){
        T e = list.front();
        list.removeFront();
        list.addFront(e);
    }
}


int main() {
    LinkedList<int> list;
    list.addFront(1);
    list.addFront(2);
    list.addFront(3);
    list.addFront(4);
    std::cout << list.toString() << std::endl;
    reverseList(list);
    std::cout << list.toString() << std::endl;

    return 0;
}
