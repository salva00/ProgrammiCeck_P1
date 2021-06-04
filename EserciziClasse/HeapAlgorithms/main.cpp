#include <iostream>
#include <vector>

template<typename TYPE>
void heapfy(std::vector<TYPE>* collection){
    std::make_heap(collection->begin(),collection->end());
}

template<typename TYPE>
TYPE maxElement(std::vector<TYPE>* collection){
    std::pop_heap(collection->begin(),collection->end());
    return collection->back();
}

template<typename TYPE>
void addToHeap(std::vector<TYPE>* collection, const TYPE& elem){
    collection->push_back(elem);
    std::push_heap(collection->begin(),collection->end());
}

int main(){
    std::vector<int> po {0,3,4,7,6,8,5};
    heapfy(&po);
    addToHeap(&po,69);      //funny number ;)
    //std::cout << maxElement(&po) << std::endl;
    return 0;
}
