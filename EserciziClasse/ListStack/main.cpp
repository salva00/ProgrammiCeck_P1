#include <iostream>
#include "ListStack.h"
int main() {
    ListStack<int> myStack;
    myStack.push(1);
    std::cout << myStack.top() << std::endl;
    myStack.push(2);
    std::cout << myStack.top() << std::endl;
    myStack.push(3);
    std::cout << myStack.top() << std::endl;
    myStack.push(4);
    std::cout << myStack.top() << std::endl;
    myStack.pop();
    std::cout << myStack.top() << std::endl;
    myStack.pop();
    std::cout << myStack.top() << std::endl;

    return 0;
}
