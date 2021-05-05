#include <iostream>
#include "LinkedList.h"
#include <string.h>

template <typename T>

void printFront(LinkedList<T> &list){
    std::cout<<list.front()<<std::endl;
}

int main() {
    LinkedList<std::string> L;
    L.addFront("kd");
    L.addFront("JK");
    printFront(L);
    LinkedList<int> L2;
    L2.addFront(1);
    L2.addFront(3);
    L2.addFront(4);
    L2.addFront(3);
    printFront(L2);
    std::cout<< L2.size()<< std::endl;
    std::cout<< L2[3]<< std::endl;

    return 0;
}