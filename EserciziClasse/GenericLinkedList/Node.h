#ifndef GENERICLINKEDLIST_NODE_H
#define GENERICLINKEDLIST_NODE_H
template<typename NODETYPE> class LinkedList;

template<typename NODETYPE>
class Node{
private:
    NODETYPE element;
    Node<NODETYPE>* next;
    friend class LinkedList<NODETYPE>;
};

#endif //GENERICLINKEDLIST_NODE_H
