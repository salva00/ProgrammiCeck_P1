//
// Created by Salvatore Bramante on 07/05/21.
//

#ifndef SPARSEMATRIX_SPARSEMATRIX_H
#define SPARSEMATRIX_SPARSEMATRIX_H
#include <string>
#include <sstream>
#include "Node.h"
template <typename T>
class SparseMatrix {
private:
    int N;
    int M;
    Node<T>** row;
    Node<T>** col;
protected:
    void addInRow (Node<T> *);
    void addInCol(Node<T> *);
public:
    SparseMatrix(int n, int m);
    ~SparseMatrix();
    void add(const T& e, int n, int m);
    void remove(int n, int m);
    std::string toString();
    const T& operator[](int n);
};



template<typename T>
SparseMatrix<T>::SparseMatrix(int n, int m){
    N=n;
    M=m;
    row = new Node<T>*[N];
    col = new Node<T>*[M];
    for( int i = 0; i < N; i++ ) row[i] = nullptr;
    for( int i = 0; i < M; i++ ) col[i] = nullptr;
    for (int i = 0; i<N; i++){
        for (int j=0; j<M; j++){
            add(0,i,j);
        }
    }


}

template<typename T>
SparseMatrix<T>::~SparseMatrix() {
    //....
    //....
    //....
    delete[] row;
    delete[] col;
}

template<typename T>
void SparseMatrix<T>::add(const T &e, int n, int m) {
    Node<T>* p = new Node<T>;
    p->element= e;
    p->rowIndex= n;
    p->colIndex = m;
    addInRow(p);
    addInCol(p);
}

template<typename T>
void SparseMatrix<T>::remove(int n, int m) {

}

template<typename T>
std::string SparseMatrix<T>::toString() {
    std::ostringstream output;

    return output.str();
}

template<typename T>
const T &SparseMatrix<T>::operator[](int n) {
    return nullptr;
}

template<typename T>
void SparseMatrix<T>::addInRow(Node<T> *p) {
    p->rowPtr = row[p->rowIndex];
    if (row[p->rowIndex]!= nullptr){
        row[p->rowIndex]->rowPtr = p;
    }
    row[p->rowIndex] = p;
}

template<typename T>
void SparseMatrix<T>::addInCol(Node<T> *p) {
    p->colPtr = col[p->colIndex];
    if (col[p->colIndex]!= nullptr){
        col[p->colIndex]->colPtr = p;
    }
    col[p->colIndex] = p;
}


#endif //SPARSEMATRIX_SPARSEMATRIX_H
