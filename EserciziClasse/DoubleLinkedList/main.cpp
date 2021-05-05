#include <iostream>
#include "LinkedList.h"
int main() {
    DoubleLinkedList<int> L;
    L.addFront(1);
    L.addFront(2);
    L.addFront(3);
    std::cout<< L.toString() << std::endl;
    return 0;
}
