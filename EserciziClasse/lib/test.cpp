
#include "mystl\ArrayStack.h"
#include "mystl\LinkedList.h"
#include "mystl\DoublyLinkedList.h"
#include "mystl\CircularLinkedList.h"
#include "mystl\LinkedStack.h"
#include "mystl\ArrayQueue.h"
#include "mystl\LinkedQueue.h"
#include "mystl\VectorPriorityQueue.h"
#include "mystl\BinarySearchTree.h"
#include "mystl\Map.h"
#include "mysort\InsertionSort.h"
#include "mysort\MergeSort.h"
#include "mysort\QuickSort.h"
#include "mysort\BubbleSort.h"
#include "mysort\HeapSort.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <cstdlib>

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
