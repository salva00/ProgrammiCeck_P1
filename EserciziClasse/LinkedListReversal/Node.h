//
// Created by Salvatore Bramante on 05/05/21.
//

#ifndef LINKEDLISTREVERSAL_NODE_H
#define LINKEDLISTREVERSAL_NODE_H

template <typename T> class LinkedList;

template <typename T>
class Node {
private:
    T element;
    Node* next;
    friend class LinkedList<T>;
};


#endif //LINKEDLISTREVERSAL_NODE_H
