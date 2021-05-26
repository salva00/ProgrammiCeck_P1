//ASSUMENDO CHE LE CHIAVI SIANO UNICHE
#include <iostream>
#include "BST.h"
int main() {
    BST<int> T;
    T.insert(2);
    T.insert(3);
    T.insert(4);
    T.insert(5);
    T.insert(6);
    T.inorderTreeWalk(2);
    //T.deleteNode(3);
    //T.printTree(1);


    return 0;
}
