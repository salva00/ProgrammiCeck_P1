//
// Created by Salvatore Bramante on 09/05/21.
//

#ifndef LINKEDQUEUE_CNODE_H
#define LINKEDQUEUE_CNODE_H

template<typename T> class CircularlyLinkedList;

template <typename T>
class Cnode {
private:
    T element;
    Cnode* next;
    friend class CircularlyLinkedList<T>;
};


#endif //LINKEDQUEUE_CNODE_H
