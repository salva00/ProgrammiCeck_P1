//
// Created by Salvatore Bramante on 03/05/21.
//

#ifndef LINKEDLIST_STRINGLINKEDLIST_H
#define LINKEDLIST_STRINGLINKEDLIST_H

#include "StringNode.h"

class StringLinkedList {
private:
    StringNode* head;
public:
    StringLinkedList();
    ~StringLinkedList();
    bool empty() const;
    const std::string& front() const;       //riferimento const
    void addFront(const std::string& e);
    void removeFront();
};


#endif //LINKEDLIST_STRINGLINKEDLIST_H
