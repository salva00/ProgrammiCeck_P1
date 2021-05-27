
#ifndef MAP_H
#define MAP_H

#include "BinarySearchTree.h"

namespace mystl {

template<typename K, typename T> class Map;

template<typename K, typename T>
bool operator<(const K&, const typename Map<K,T>::Entry&);

template<typename K, typename T>
// K requires operator< and operator==
class Map {
private:
public:
	class Entry {
		friend class Map;
	private:
	public:
		K key;
		T value;
		Entry(K, T);
		bool operator<(const Entry&) const;
		bool operator==(const Entry&) const;
		bool operator<(const K&) const;
		bool operator==(const K&) const;
		template<typename KK, typename TT>
		friend bool operator<(const KK&, const Entry&);
		// friend bool operator== <>(const K&, const Entry&);
	};
using Iterator = typename BinarySearchTree<Entry>::Iterator;
private:
	BinarySearchTree<Entry> elements;
public:
	Map();
	bool empty() const;
	size_t size() const;
	T& operator[](const K&);
	void insert(const K&, const T&);
	void erase(const K&);
	void swap(Iterator, Iterator);
	void clear() const;
	Iterator find(const K&) const;
	Iterator begin() const;
	Iterator end() const;
	Iterator rbegin() const;
	Iterator rend() const;
};



// Entry //

template<typename K, typename T>
Map<K,T>::Entry::Entry(K k, T val) : key{k}, value{val} {}

template<typename K, typename T>
bool Map<K,T>::Entry::operator<(const Entry& rhs) const {
	return this->key < rhs.key;
}

template<typename K, typename T>
bool Map<K,T>::Entry::operator==(const Entry& rhs) const {
	return this->key == rhs.key;
}

template<typename K, typename T>
bool Map<K,T>::Entry::operator<(const K& rhs) const {
	return this->key < rhs;
}

// template<typename K, typename T>
// bool Map<K,T>::Entry::operator==(const K& rhs) const {
// 	return this->key == rhs;
// }


template<typename K, typename T>
bool operator<(const K& key, const typename Map<K,T>::Entry& entry) {
	return key < entry.key;
}

// Map //

template<typename K, typename T>
Map<K,T>::Map() : elements{} {}

template<typename K, typename T>
bool Map<K,T>::empty() const {return elements.empty();}

template<typename K, typename T>
size_t Map<K,T>::size() const {return elements.size();}

template<typename K, typename T>
T& Map<K,T>::operator[](const K& key) {
	return *(elements.search(key));
}


}//end namespace mystl

#endif










//
