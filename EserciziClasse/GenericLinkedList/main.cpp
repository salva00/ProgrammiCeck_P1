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
    printFront(L2);
    return 0;
}