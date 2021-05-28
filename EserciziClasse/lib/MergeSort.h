
#ifndef MERGESORT_H
#define MERGESORT_H

// REQUIRES: random access iterator
// operator-(iterator, size_t)
// operator+(iterator,size_t)
// operator<(iterator,iterator)
// operator-(iterator,iterator)
// operator*(iterator)
// operator++(iterator, int) pre
// operator--(iterator) post
// operator<=(T,T)

namespace mysort {

	template<class Iterator>
	void merge_sort(const Iterator&, const Iterator&);

	template<class Iterator>
	void merge(const Iterator&, const Iterator&, const Iterator&);

}

template<class Iterator>
void mysort::merge_sort(const Iterator& begin, const Iterator& end) {
	using mysort::merge;
	Iterator rend = end-1;
	if(begin < rend) {
		Iterator mid = begin + (end - begin)/2; //middle at right
		merge_sort(begin, mid);
		merge_sort(mid, end);
		merge(begin, end, mid);
	}
	return;
}

template<class Iterator>
void mysort::merge(const Iterator& begin, const Iterator& end, const Iterator& mid) {
	static Iterator left, right;
	left = begin, right = mid;
	size_t k = 0;
	typename Iterator::value_type temp[end-begin];
	while(left < mid && right < end) {
		if(*left <= *right) {
			temp[k++] = *(left++);
		} else {
			temp[k++] = *(right++);
		}
	}
	while(left < mid) temp[k++] = *(left++);
	while(right < end) temp[k++] = *(right++);

	while(k > 0) {
		*(--right) = temp[--k];
	}
	return;
}


#endif













//
