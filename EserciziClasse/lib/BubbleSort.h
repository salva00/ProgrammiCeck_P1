
#ifndef BUBBLESORT_H
#define BUBBLESORT_H

// REQUIRES: forward_iterator
// operator!=(iterator,iterator)
// operator++(iterator)

namespace mysort {

template<class Iterator>
void bubble_sort(Iterator begin, Iterator end);

}

// #include <iostream>

// template<class Iterator>
// inline void print(const Iterator& begin, const Iterator& end) {
// 	for(auto it = begin; it != end; ++it) {
// 		std::cout << *it << ' ';
// 	}
// 	std::cout << '\n';
// 	return;
// }

template<class Iterator>
void mysort::bubble_sort(Iterator begin, Iterator end) {
	for (Iterator i = begin; i != end; ++i)
			for (Iterator j = begin; j < i; ++j)
					if (*i < *j) std::iter_swap(i, j);
}


#endif
