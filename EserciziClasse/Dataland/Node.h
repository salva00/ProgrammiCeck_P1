//
// Created by Salvatore Bramante on 31/05/21.
//

#ifndef DATALAND_NODE_H
#define DATALAND_NODE_H
template<typename NODETYPE> class LinkedList;

template<typename NODETYPE>
class Node{
private:
    NODETYPE element;
    Node<NODETYPE>* next;
    friend class LinkedList<NODETYPE>;
};

#endif //DATALAND_NODE_H
