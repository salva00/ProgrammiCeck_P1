#include <iostream>
#include "LinkedList.h"

template<typename NODETYPE>
void splitIntoEvenAndOdd(LinkedList<NODETYPE>* toSpit, LinkedList<NODETYPE>* even,LinkedList<NODETYPE>* odd ){
    while (!toSpit->empty()){
        if (toSpit->front() % 2 == 0){
            even->addFront(toSpit->front());
        } else{
            odd->addFront(toSpit->front());
        }
        toSpit->removeFront();
    }
}

int main() {
    LinkedList<int> L;

    L.addFront(1);
    L.addFront(2);
    L.addFront(3);
    L.addFront(4);

    LinkedList<int> P;
    LinkedList<int> D;

    splitIntoEvenAndOdd(&L,&P,&D);


    return 0;
}
