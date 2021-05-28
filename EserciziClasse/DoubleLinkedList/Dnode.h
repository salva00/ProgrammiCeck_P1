
#ifndef DOUBLELINKEDLIST_DNODE_H
#define DOUBLELINKEDLIST_DNODE_H

template <typename T> class DoubleLinkedList;

template <typename T>
class Dnode {
private:
    T element;
    Dnode* next;
    Dnode* prev;
    friend class DoubleLinkedList<T>;
};


#endif //DOUBLELINKEDLIST_DNODE_H
