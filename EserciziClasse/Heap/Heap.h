//template funzioni Heapify, HeapSort, BuildHeap

#include <vector>

template <typename T>
void swap(std::vector<T>& A,int x, int y){
    T temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

template <typename T>
void Heapify(std::vector<T>& A,unsigned int i,unsigned int heapSize){
	unsigned int l=2*i;
	unsigned int r=2*i+1;
	unsigned int largest;
	if(l<=heapSize && A[l-1]>A[i-1]){
		largest=l;
	}
	else{
		largest=i;
	}
	if(r<=heapSize && A[r-1]>A[largest-1]){
		largest=r;                         //massimo tra il padre e i due figli.
	}
	if(largest!=i){
		swap(A,largest-1,i-1);
	}
	else{
		return;
	}
	Heapify(A,largest,heapSize);                   //fa scendere il minimo lungo un ramo
}


template <typename T>
void BuildHeap(std::vector<T>& A){
	unsigned int heapSize{A.size()};
	for(unsigned int i{heapSize/2};i>=1;i--){   //Non applico Heapify alle foglie, dunque parto dal penultimo livello,
		Heapify(A,i,heapSize);                  //fino alla radice
	}
}


template<typename T>
void HeapSort(std::vector<T>& A){
	BuildHeap(A);
	for(unsigned int i{A.size()};i>=2;i--){
		swap(A,0,i-1);
		Heapify(A,1,i-1);
	}
}


template<typename T>
void HeapInsert(std::vector<T>& A,const T& key){
	A.push_back(key);
	unsigned int i{A.size()};
	while(i>1 && A[(i/2)-1]<key){
		A[i-1]=A[(i/2)-1];
		i=i/2;
	}
	A[i-1]=key;
}



