//
// Created by Salvatore Bramante on 05/05/21.
//

#ifndef DOUBLELINKEDLIST_DNODE_H
#define DOUBLELINKEDLIST_DNODE_H

template <typename T> class DoubleLinkedList<T>;

template <typename T>
class Dnode {
private:
    T element;
    Dnode* next;
    Dnode* prev;
    friend class DoubleLinkedList<T>;
};


#endif //DOUBLELINKEDLIST_DNODE_H
