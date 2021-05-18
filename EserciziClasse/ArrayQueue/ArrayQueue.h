//ArrayQueue
#ifndef ARRAYQUEUE
#define ARRAYQUEUE

#include <stdexcept>
using std::runtime_error;


template <typename T>
class ArrayQueue{
public:
	ArrayQueue(int);
	int size() const;
	bool empty() const;
	const T& front() const;
	void enqueue(const T&);
	void dequeue();
	bool full() const;
private:
	int N;
	T* queue;
	int head;
	int tail;
};

template <typename T>
ArrayQueue<T>::ArrayQueue(int n)
	:N{n},queue{new T[n]{}},head{0},tail{0}{}


template <typename T>
int ArrayQueue<T>::size() const{
	return N;
}

template <typename T>
const T& ArrayQueue<T>::front() const{
	if (empty()){
        throw std::runtime_error("Stack empty");
    }
	return queue[head];
}

template <typename T>
bool ArrayQueue<T>::empty() const{
	return head==tail;
}

template <typename T>
bool ArrayQueue<T>::full() const{
	return head==tail+1;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& element){
	queue[tail]=element;
	if(tail==N-1){
		tail=0;
	}
	else{
		tail+=1;
	}
}

template <typename T>
void ArrayQueue<T>::dequeue(){
	queue[head]=0;
	if(head==N-1){
		head=0;
	}
	else{
		head+=1;
	}
}



#endif




