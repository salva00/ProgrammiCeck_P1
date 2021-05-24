//
// Created by Salvatore Bramante on 24/05/21.
//

#ifndef PARIDISPARILINKEDLIST_NODE_H
#define PARIDISPARILINKEDLIST_NODE_H
template<typename NODETYPE> class LinkedList;

template<typename NODETYPE>
class Node{
private:
    NODETYPE element;
    Node<NODETYPE>* next;
    friend class LinkedList<NODETYPE>;
};

#endif //PARIDISPARILINKEDLIST_NODE_H
