//main.cpp
#include <iostream>
#include "ArrayQueue.h"

int main() {
    ArrayQueue<int> coda(4);
    coda.enqueue(2);
    coda.enqueue(4);
    coda.enqueue(5);
    coda.enqueue(6);
    std::cout << coda.front() << std::endl;
    coda.dequeue();
    std::cout << coda.front() << std::endl;
    coda.dequeue();
    std::cout << coda.front() << std::endl;
    coda.dequeue();
    std::cout << coda.front() << std::endl;

    return 0;
}