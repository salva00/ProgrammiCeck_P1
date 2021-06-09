
#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

// REQUIRES: bidirectional_iterator
// operator++(iterator)
// operator--(iterator)
// operator-(iterator, size_t)
// operator*(iterator)

namespace mysort {

	template<class Iterator>
	void insertion_sort(const Iterator&, const Iterator&);

}


template<class Iterator>
void mysort::insertion_sort(const Iterator& begin, const Iterator& end) {
	for(Iterator it = begin; it != end; ++it) {
		auto key = *it;
		Iterator it2 = it;
		while(it2 != begin && key < *(it2-1)) {
			*it2 = *(it2-1);
			--it2;
		}
		*it2 = key;
	}
	return;
}


#endif
