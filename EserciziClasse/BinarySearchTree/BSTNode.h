//
// Created by Salvatore Bramante on 19/05/21.
//

#ifndef BINARYSEARCHTREE_BSTNODE_H
#define BINARYSEARCHTREE_BSTNODE_H
#include <iostream>
template<typename Key>class BST;

template<typename Key>
class BSTNode {
private:
    friend class BST<Key>;
    Key key;
    BSTNode<Key> *left;
    BSTNode<Key> *right;
    BSTNode<Key> *parent;
public:
    BSTNode(Key k, BSTNode<Key> *l= nullptr, BSTNode<Key> *r= nullptr, BSTNode<Key> *p= nullptr)
        : key(k),left(l),right(r),parent(p){}
};


#endif //BINARYSEARCHTREE_BSTNODE_H
