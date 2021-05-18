//
// Created by Salvatore Bramante on 18/05/21.
//

#ifndef HEAPIFY_POSITION_H
#define HEAPIFY_POSITION_H
class Position { private:
    Node* v; public:
    Position(Node* v = NULL) : v( v) { } Elem& operator*()
    { return v−>elt; } Position left() const
    { return Position(v−>left); } Position right() const
    { return Position(v−>right); } Position parent() const
    { return Position(v−>par); } bool isRoot() const
    { return v−>par == NULL; } bool isExternal() const
// position in the tree
// pointer to the node
// constructor // get element
// get left child
// get right child // get parent
// root of the tree?
// an external node?
// a node of the tree // element value
// parent
// left child
// right child
    { return v−>left == NULL && v−>right == NULL; }
    friend class LinkedBinaryTree; // give tree access
};
typedef std::list<Position> PositionList; // list of positions
#endif //HEAPIFY_POSITION_H
