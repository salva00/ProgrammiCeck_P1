//ASSUMENDO CHE LE CHIAVI SIANO UNICHE
#include <iostream>
#include "BST.h"
int main() {
    BST<int> T;
    T.insert(10);
    T.insert(3);
    T.insert(2);
    T.inorderTreeWalk();
    T.deleteNode(3);
    T.inorderTreeWalk();

    return 0;
}
