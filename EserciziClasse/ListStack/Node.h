//
// Created by Salvatore Bramante on 06/05/21.
//

#ifndef LISTSTACK_NODE_H
#define LISTSTACK_NODE_H
template<typename NODETYPE> class LinkedList;

template<typename NODETYPE>
class Node{
private:
    NODETYPE element;
    Node<NODETYPE>* next;
    friend class LinkedList<NODETYPE>;
};

#endif //LISTSTACK_NODE_H
