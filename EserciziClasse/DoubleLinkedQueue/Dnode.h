//
// Created by Salvatore Bramante on 09/05/21.
//

#ifndef DOUBLELINKEDQUEUE_DNODE_H
#define DOUBLELINKEDQUEUE_DNODE_H
template <typename T> class DoubleLinkedList;

template <typename T>
class Dnode {
private:
    T element;
    Dnode* next;
    Dnode* prev;
    friend class DoubleLinkedList<T>;
};


#endif //DOUBLELINKEDQUEUE_DNODE_H
