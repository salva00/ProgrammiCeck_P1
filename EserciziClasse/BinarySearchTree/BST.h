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
    BST(BSTNode<Key>* r = nullptr) : root(r){}
    ~BST(){release(root);}

    //traverse
    void inorderTreeWalk(BSTNode<Key>*x);
    void inorderTreeWalk(){ inorderTreeWalk(root);}

    //accessors
    BSTNode<Key>* getRoot() {return root;}
    BSTNode<Key>* search(Key key);
    BSTNode<Key>* search(BSTNode<Key>*x,Key key);
    BSTNode<Key>* minimum(BSTNode<Key> *subRoot);
    BSTNode<Key>* minimum(){minimum(root);};
    BSTNode<Key>* maximum(BSTNode<Key> *subRoot);
    BSTNode<Key>* maximum(){maximum(root);};
    BSTNode<Key>* predecessor(BSTNode<Key> *x);
    BSTNode<Key>* successor(BSTNode<Key> *x);

    //Modifiers
    BSTNode<Key>* insert(Key key);
    void release (BSTNode<Key>* x);
    void deleteNode(Key key);
    BSTNode<Key>* deleteNode(BSTNode<Key>* subRoot, Key key);


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
    std::free(x);
}

/*
template<typename Key>
BSTNode<Key> *BST<Key>::deleteNode(Key key) {
    if (!search(key)) return nullptr;
    if(key<root->key)                   // If key is smaller than root
        root->left =deleteNode(key);

    else if(key > root->key){            // If key is greater than root
        root->right = deleteNode(key);
        }
    else{                               // If key is root
        if(root->left == nullptr){
            BSTNode<Key> * temp = root->right;
            release(root);
            return temp;
        }
        else if(root->right== nullptr){
            BSTNode<Key> * temp = root->left;
            release(root);
            return temp;
        }
        BSTNode<Key> * temp = minimum(root->right);

        root->key = temp->key;

        root->right = deleteNode(temp->key);
    }

    return root;

}
*/

template<typename Key>
void BST<Key>::deleteNode(Key key){
    if (search(key)) 
		  root = deleteNode(root,key);
    return;
}

template<typename Key>
BSTNode<Key> *BST<Key>::deleteNode(BSTNode<Key>* subRoot, Key key) { 
    if(key<subRoot->key)                // If key is smaller than subRoot
        subRoot->left = deleteNode(subRoot->left, key);
    else if(key > subRoot->key)          // If key is greater than subRoot
        subRoot->right = deleteNode(subRoot->right,key);
    else{                               // If key is root
        if(subRoot->left == nullptr){
            BSTNode<Key> * temp = subRoot->right;
            release(subRoot);
            return temp;
        }
        else if(subRoot->right== nullptr){
            BSTNode<Key> * temp = subRoot->left;
            release(subRoot);
            return temp;
        }
        BSTNode<Key> * temp = minimum(subRoot->right);

        subRoot->key = temp->key;

        subRoot->right = deleteNode(subRoot->right, temp->key);
    }
    return subRoot;
}


#endif //BINARYSEARCHTREE_BST_H
