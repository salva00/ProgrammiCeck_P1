//
// Created by Salvatore Bramante on 19/05/21.
//

#ifndef BINARYSEARCHTREE_BST_H
#define BINARYSEARCHTREE_BST_H
#include "BSTNode.h"

template<typename Key>
class BST {
protected:
    BSTNode<Key> * root;
public:
    //constructors
    BST(BSTNode<Key>* r = NULL) : root(r){}
    ~BST(){release(root);}

    //traverse
    void inorderTreeWalk(BSTNode<Key>*x);
    void inorderTreeWalk(){ inorderTreeWalk(root)}

    //accessors
    BSTNode<Key>* getRoot() {return root;}
    BSTNode<Key>* search(Key key);
    BSTNode<Key>* search(BSTNode<Key>*x,Key key);
    BSTNode<Key>* minimum(BSTNode<Key> *subRoot);
    BSTNode<Key>* minimum(){minimum(root)};
    BSTNode<Key>* maximum(BSTNode<Key> *subRoot);
    BSTNode<Key>* maximum(){maximum(root)};
    BSTNode<Key>* predecessor(BSTNode<Key> *x);
    BSTNode<Key>* successor(BSTNode<Key> *x);

    //Modifiers
    BSTNode<Key>* insert(Key key);
    void release (BSTNode<Key>* x);
    BSTNode<Key>* deleteNode(Key key);


};

template<typename Key>
void BST<Key>::inorderTreeWalk(BSTNode<Key> *x) {
    if(x){
        inorderTreeWalk(x->left);
        std::cout<<x->key<<'\n';
        inorderTreeWalk(x->right);
    }
}

template<typename Key>
BSTNode<Key> *BST<Key>::search(BSTNode<Key> *x, Key key) {
    while (x){
        if (x->key==key) break;
        else if(x->key<key) x=x->right;
        else x = x->left;
    }
    return x;
}

template<typename Key>
BSTNode<Key> *BST<Key>::search(Key key) {
    return search(root,key);
}

template<typename Key>
BSTNode<Key> *BST<Key>::minimum(BSTNode<Key> *subRoot) {
   BSTNode<Key>* x = subRoot;
    if (x){
        while (x->left) x = x->left;
    }
    return x;
}

template<typename Key>
BSTNode<Key> *BST<Key>::maximum(BSTNode<Key> *subRoot) {
    BSTNode<Key>* x = subRoot;
    if (x){
        while (x->right) x = x->right;
    }
    return x;
}

template<typename Key>
BSTNode<Key> *BST<Key>::predecessor(BSTNode<Key> *x) {
    BSTNode<Key>* prev = nullptr;
    if(x->left) prev = maximum(x->left);
    else{
        prev = x->parent;
        while (prev&&prev->left==x){
            x=prev;
            prev = x->parent;
        }
    }
    return prev;
}

template<typename Key>
BSTNode<Key> *BST<Key>::successor(BSTNode<Key> *x) {
    BSTNode<Key>* succ = nullptr;
    if(x->right) succ = maximum(x->right);
    else{
        succ = x->parent;
        while (succ && succ->right==x){
            x=succ;
            succ = x->parent;
        }
    }
    return succ;
}

template<typename Key>
BSTNode<Key> *BST<Key>::insert(Key key) {
    if (search(key)) return nullptr;
    BSTNode<Key> *x=root;
    BSTNode<Key> *y= nullptr;
    BSTNode<Key> *z= new BSTNode<Key>(key);
    while (x){
        y=x;
        if(z->key < x->key) x = x->left;
        else x = x->right;
    }
    z->parent = y;
    if (y== nullptr)
        root = z;
    else{
        if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
    }
    return z;
}

template<typename Key>
void BST<Key>::release(BSTNode<Key> *x) {

}

template<typename Key>
BSTNode<Key> *BST<Key>::deleteNode(Key key) {
    return nullptr;
}


#endif //BINARYSEARCHTREE_BST_H
