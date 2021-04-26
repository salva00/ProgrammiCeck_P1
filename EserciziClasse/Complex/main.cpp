#include <iostream>
#include "Complex.h"
int main() {
    Complex com1;
    com1.setImag(3.0);
    com1.setReal(2.5);

    Complex com2;

    com2.setImag(4);

    com1= com1/com2;

    std::cout << com1.toString() << std::endl;
    return 0;
}
