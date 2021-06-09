
#ifndef QUICKSORT_H
#define QUICKSORT_H

// REQUIRES: bidirectional_iterator
// operator!=(iterator,iterator)
// operator++(iterator)
// operator--(iterator)

// template<class Iterator>
// void swap(const Iterator&, const Iterator&);

namespace mysort {

	template<class Iterator>
	Iterator partition(Iterator, Iterator);

	template<class Iterator>
	void quick_sort(const Iterator&, const Iterator&);

}

// template<class Iterator>
// void swap(const Iterator& first, const Iterator& second) {
// 	auto temp = *first;
// 	*first = *second;
// 	*second = temp;
// 	return;
// }

template<class Iterator>
void mysort::quick_sort(const Iterator& begin, const Iterator& end) {
	using mysort::partition;
	// std::getchar();
	// std::cout << "-----\n";
	if(begin != end) {
		Iterator split = partition(begin, end);
		// std::cout << "split at " << *split << '\n';
		// std::cout << "first:\n";
		quick_sort(begin, split);
		// std::cout << "second:\n";
		quick_sort(++split, end);
	} else {
		// std::cout << "end thread\n";
	}
	return;
}

// template<class Iterator>
// inline void print(const Iterator& begin, const Iterator& end) {
// 	for(auto it = begin; it < end; ++it) {
// 		std::cout << *it << ' ';
// 	}
// 	std::cout << '\n';
// 	return;
// }

template<class Iterator>
Iterator mysort::partition(Iterator begin, Iterator end) {

	// auto b = begin, e = end;
	--end;
	static Iterator pivot{begin};
	pivot = begin;
	// print(b,e);
	while(true) {
		while(*pivot < *end) {
			--end;
			// print(b,e);
			// std::cout << "-begin at " << *begin << " end at " << *end << '\n';
		}
		while((*begin < *pivot || *begin == *pivot) && begin != end) {
			++begin;
			// print(b,e);
			// std::cout << "+begin at " << *begin << " end at " << *end << '\n';
		}
		// std::cout << "difference " << end - begin << '\n';
		if(begin != end) {
			std::iter_swap(begin,end);
			// print(b,e);
			// std::cout << "sbegin at " << *begin << " end at " << *end << '\n';
		} else {
			std::iter_swap(pivot,end);
			// print(b,e);
			// std::cout << "end: returning " << *end << '\n';
			return end;
		}
	}
}



#endif









//
