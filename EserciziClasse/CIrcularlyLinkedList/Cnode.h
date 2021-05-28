
#ifndef CIRCULARLYLINKEDLIST_CNODE_H
#define CIRCULARLYLINKEDLIST_CNODE_H

template<typename T> class CircularlyLinkedList;

template <typename T>
class Cnode {
private:
    T element;
    Cnode* next;
    friend class CircularlyLinkedList<T>;
};


#endif //CIRCULARLYLINKEDLIST_CNODE_H
