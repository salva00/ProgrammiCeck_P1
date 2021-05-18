//main.cpp

#include "Heap.h"
#include <vector>
#include <iostream>
using std::cout;
using std::vector;

int main(){
	vector<int> A{7,3,4,3,5,9,12,15,17};
	BuildHeap(A);
	cout<<"L'heap implementato con un vettore e: ";
	for(int i: A){
		cout<<i<<" ";
	}
	HeapInsert(A,10);
	cout<<"\n\nIl nuovo heap dopo l'insert di 10 implementato con un vettore e: ";
	for(int i: A){
		cout<<i<<" ";
	}
	cout<<"\n\n\n";
	cout<<"Ordinato: ";
	HeapSort(A);
	for(int i: A){
		cout<<i<<" ";
	}
}