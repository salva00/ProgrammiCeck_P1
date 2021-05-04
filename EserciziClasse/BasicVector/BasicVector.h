
//
// Created by Salvatore Bramante on 04/05/21.
//

#ifndef BASICVECTOR_BASICVECTOR_H
#define BASICVECTOR_BASICVECTOR_H

template <typename T>
class BasicVector {
private:
    T* a;           //array storing the data
    int capacity;   //lenght of array a
public:
    BasicVector(int cap = 10);
    T& operator[](int i){ return a[i];};
};

template<typename T>
BasicVector<T>::BasicVector(int cap) {
    capacity=cap;
    a = new T[capacity];        //allocate array storage
}


#endif //BASICVECTOR_BASICVECTOR_H
