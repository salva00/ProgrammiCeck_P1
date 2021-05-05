#include <iostream>
#include "LinkedList.h"
#include <string.h>


int main() {
    LinkedList<std::string> L;
    L.addFront("kd");
    L.addFront("JK");
    std::cout << L.front() << std::endl;
    LinkedList<int> L2;
    L2.addFront(1);
    L2.addFront(3);
    std::cout << L2.front() << std::endl;
    return 0;
}
