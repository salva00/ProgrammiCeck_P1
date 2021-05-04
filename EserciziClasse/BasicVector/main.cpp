#include <iostream>
#include "BasicVector.h"
int main() {
    BasicVector<double> v(10);
    for (int i = 0; i<10 ; i++)
        v[i] = i/2;
    for (int i = 0; i<10 ; i++)
        std::cout << v[i]<< " " ;
    return 0;
}
