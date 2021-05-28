
#ifndef HEAPIFY_COMPLETETREE_H
#define HEAPIFY_COMPLETETREE_H
#include <vector>
template<typename T>
class CompleteTree {
private:
    std::vector<T> treeElements;                        //tree contents
public:
    typedef typename std::vector<T>::iterator Position; // a postion in the tree
    int size() const;				                    // number of elements
    Position left(const Position& p){ return pos(2*idx(p));};		            // get left child
    Position right(const Position& p){return pos(2*idx(p)+1);}		            // get right child
    Position parent(const Position& p){ return pos(idx(p)/2);}		            // get parent
    bool hasLeft(const Position& p) const;	            // does node have left child?
    bool hasRight(const Position& p) const;	            // does node have right child?
    bool isRoot(const Position& p) const;	            // is this the root?
    Position root(){return pos(1);}				                    // get root position
    Position last(){return pos(size());};				                    // get last node
    void addLast(const T& e);			                // add a new last node
    void removeLast();				                    // remove the last node
    void swap(const Position& p, const Position& q);    // swap node contents
protected:
    Position pos(int i){                                // map an index to a position
        return treeElements.begin() + i;
    }
    int idx(const Position& p) const{                   //map a position to an index
        return p-treeElements.begin();
    }
};

template<typename T>
int CompleteTree<T>::size() const {
    return treeElements.size()-1;
}


template<typename T>
bool CompleteTree<T>::hasLeft(const Position &p) const {
    return 2*idx(p)<=size();
}

template<typename T>
bool CompleteTree<T>::hasRight(const Position &p) const {
    return 2*idx(p)+1<=size();
}

template<typename T>
bool CompleteTree<T>::isRoot(const Position &p) const {
    return idx(p) == 1;
}


template<typename T>
void CompleteTree<T>::addLast(const T &e) {
    treeElements.push_back(e);
}

template<typename T>
void CompleteTree<T>::removeLast() {
    treeElements.pop_back();
}

template<typename T>
void CompleteTree<T>::swap(const Position &p, const Position &q) {
    T e = *q;
    *q=*p;
    *p=e;
}


#endif //HEAPIFY_COMPLETETREE_H
