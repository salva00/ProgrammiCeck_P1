#include <iostream>
#include "LinkedList.h"
#include <string.h>

template <typename T>

void printFront(LinkedList<T> &list){
    std::cout<<list.front()<<std::endl;
}

int main() {
	// typedef LinkedList<int> lis;
	using lis = LinkedList<int>;
	lis l1;
	{
		lis l2;
		l2.addFront(2);
		l2.addFront(1);
		lis l3{l2};
		std::cout << l3[0] << " " << l3[1] << '\n';
		l1 = l3;
	}
	std::cout << l1[0] << " " << l1[1] << '\n';
	std::cout << "Press enter to exit";
	getchar();
	return 0;
}
