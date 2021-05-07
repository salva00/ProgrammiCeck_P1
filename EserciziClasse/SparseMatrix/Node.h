//
// Created by Salvatore Bramante on 07/05/21.
//

#ifndef SPARSEMATRIX_NODE_H
#define SPARSEMATRIX_NODE_H

template<typename T> class SparseMatrix;

template<typename T>
class Node {
    int rowIndex;
    int colIndex;
    T element;
    Node* rowPtr;
    Node* colPtr;
    friend class SparseMatrix<T>;

};


#endif //SPARSEMATRIX_NODE_H
