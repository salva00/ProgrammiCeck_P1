
#include "..\lib\LinkedList.h"
#include <iostream>

template<typename T>
void listReverse(mystl::LinkedList<T>&);

int main() {
	mystl::LinkedList<int> list;
	list.push_front(5);
	list.push_front(4);
	list.push_front(3);
	list.push_front(2);
	list.push_front(1);
	for(auto i : list) std::cout << i << ' ';
	std::cout << '\n';
	listReverse(list);
	for(auto i : list) std::cout << i << ' ';
	std::cout << '\n';
	return 0;
}


template<typename T>
void listReverse(mystl::LinkedList<T>& list) {
	using Iterator = typename mystl::LinkedList<T>::Iterator;
	size_t n = list.size();
	if(n < 2) return;
	Iterator oldBeg = list.begin();
	Iterator it = list.begin();
	while(++it != list.end()) list.push_front(*it);
	while(list.size() > n) list.erase_after(oldBeg);
	return;
}









//
