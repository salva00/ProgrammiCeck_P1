
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
	auto b = begin, e = end;
	for (Iterator sorted = begin; begin != end; end = sorted ) {
		sorted = begin;
		for (Iterator current = begin, prev = begin; ++current != end; ++prev) {
			// mysort::print(b,e);
			if(*current < *prev) {
				std::iter_swap(current, prev);
				// std::cout << "swap!\n";
				// mysort::print(b,e);
				sorted = current;
			}
		}
	}
}




#endif
