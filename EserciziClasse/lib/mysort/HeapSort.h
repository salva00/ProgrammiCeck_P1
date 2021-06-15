
#ifndef HEAPSORT_H
#define HEAPSORT_H

// REQUIRES: random_access_iterator
// operator+(iterator,int)
// operator-(iterator,int)
// operator-(iterator,iterator)
// operator!=(iterator,iterator)
// operator--(iterator)

namespace mysort {

	template<class Iterator>
	void heapify(const Iterator&, const Iterator&, const Iterator&);

	template<class Iterator>
	void build_heap(const Iterator&, const Iterator&);

	template<class Iterator>
	void push_heap(const Iterator&, const Iterator&);

	template<class Iterator>
	void heap_sort(const Iterator&, const Iterator&);

	template<class Iterator>
	inline Iterator parent(const Iterator&, const Iterator&);

	template<class Iterator>
	inline Iterator lchild(const Iterator&, const Iterator&);

	template<class Iterator>
	inline Iterator rchild(const Iterator&, const Iterator&);

}

// #include<iostream>
// template<class Iterator>
// void print(const Iterator& begin, const Iterator& end) {
// 	int x = 1, i = 0;
// 	Iterator it{begin};
// 	while(it != end) {
// 		// for(int j = 0; j < 10 - x; ++j) std::cout << ' ';
// 		while(it != end && i < x) {
// 			std::cout << *it++ << ' ';
// 			++i;
// 		}
// 		std::cout << '\n';
// 		x *= 2;
// 		i = 0;
// 	}
// 	std::cout << '\n';
// 	return;
// }

template<class Iterator>
inline Iterator mysort::parent(const Iterator& begin, const Iterator& i) {
	return begin + ((i-begin)-1)/2;
}

template<class Iterator>
inline Iterator mysort::lchild(const Iterator& begin, const Iterator& i) {
	return i+(i-begin)+1;
}
template<class Iterator>
inline Iterator mysort::rchild(const Iterator& begin, const Iterator& i) {
	return i+(i-begin)+2;
}

template<class Iterator>
void mysort::heapify(const Iterator& begin, const Iterator& end, const Iterator& target) {
	using mysort::rchild;
	using mysort::lchild;
	using mysort::heapify;
	// getchar();
	// std::cout << "====\n";
	// ::print(begin, end);
	Iterator largest = target;

	// std::cout << 2*(target - begin) << "<=" << end - begin << " ~ ";
	if(2*(target - begin + 1) <= (end - begin)) {
		// std::cout << "###" <<  *lchild(begin,target) << "\n";
		if(*target < *lchild(begin,target)) largest = lchild(begin,target);
	}

	// std::cout << 2*(target - begin + 1) << "<" << end - begin << " ~ ";
	if(2*(target - begin + 1) < (end - begin)) {
		// std::cout << "###" <<  *rchild(begin,target) << '\n';
		if(*largest < *rchild(begin,target)) largest = rchild(begin,target);
	}
	// std::cout << "target: " << *target << " ~ " << "largest: " << *largest << '\n';
	if(largest != target) {
		std::iter_swap(largest,target);
		heapify(begin, end, largest);
	}
	return;
}

template<class Iterator>
void mysort::heap_sort(const Iterator& begin, const Iterator& end) {
	using mysort::heapify;
	using mysort::build_heap;

	build_heap(begin, end);
	Iterator it = end;
	// ::print(begin, end);
	while(it != begin) {
		// std::cout << "===\n";
		std::iter_swap(begin, --it);
		// ::print(begin, end);
		heapify(begin, it, begin);
		// ::print(begin, end);
		// std::cout << "it @ " << *it << '\n';
	}
	return;
}

template<class Iterator>
void mysort::build_heap(const Iterator& begin, const Iterator& end) {
	using mysort::heapify;
	Iterator it = begin + (end - begin)/2;
	while(it != begin) {
		heapify(begin, end, --it);
	}
	return;
}

template<class Iterator>
void mysort::push_heap(const Iterator& begin, const Iterator& end) {
	using mysort::parent;
	Iterator i = end-1;
	for(Iterator par = parent(begin,i); i != begin && *par < *i;) {
		std::iter_swap(i,par);
		i = par;
		par = parent(begin, par);
	}
	return;
}

#endif







//
