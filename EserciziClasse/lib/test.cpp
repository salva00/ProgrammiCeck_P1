
// #include "ArrayStack.h"
// #include "LinkedList.h"
// #include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
// #include "LinkedStack.h"
// #include "ArrayQueue.h"
// #include "LinkedQueue.h"
#include <iostream>
// #include "InsertionSort.h"
// #include "MergeSort.h"
// #include "QuickSort.h"
// #include "BubbleSort.h"
// #include "HeapSort.h"
// #include <vector>
// #include <cstdlib>
// #include <ctime>
// #include "VectorPriorityQueue.h"
// #include "BinarySearchTree.h"
// #include "Map.h"
#include <algorithm>

// using namespace mystl;
// using namespace mysort;

int main() {
	using list = mystl::CLinkedList<int>;

	list l(1,1);
	l.push_front(7);
	l.push_back(2);
	l.push_back(3);
// l: 7 1 2 3

	list::Iterator it = l.begin();
// it -> 7 (it.firstnode = 7)
	++it;
// it -> 1
	l.pop_front();
// l: 1 2 3
	while(it++ != l.end()) std::cout << *it << ' ';
	std::cout << '\n';

	std::cout << "End";
	getchar();
	return 0;
}







//
