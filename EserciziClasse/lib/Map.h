
#ifndef MAP_H
#define MAP_H

#include "BinarySearchTree.h"

namespace mystl {

template<typename K, typename T>
// K requires operator< and operator==
class Map {
private:
	class Entry {
		friend class Map;
	private:
		Entry(K, T = T());
	public:
		K key;
		T value;
		bool operator<(const Entry&) const;
		bool operator==(const Entry&) const;
	};
using Iterator = typename BinarySearchTree<Entry>::Iterator;
private:
	BinarySearchTree<Entry> elements;
public:
	Map();
	// default constructor
	bool empty() const;
	// returns true if empty
	size_t size() const;
	// returns size
	const T& at(const K&) const;
	// access elements
	void insert(const K&, const T&);
	// insert elments
	T& operator[](const K&);
	// access elements/ create new element
	void erase(const K&);
	// delete element with key #1
	void swap(const Iterator&, const Iterator&);
	// swap elements with key #1 and #2
	void clear() const;
	// delete all entries
	Iterator find(const K&) const;
	// return iterator to value with key #1
	Iterator begin() const;
	// return iterator to begin
	Iterator end() const;
	// return iterator to end
	Iterator rbegin() const;
	// return iterator to reverse begin
	Iterator rend() const;
	// return iteratro to rever end
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

// Map //

template<typename K, typename T>
Map<K,T>::Map() : elements{} {}

template<typename K, typename T>
bool Map<K,T>::empty() const {return elements.empty();}

template<typename K, typename T>
size_t Map<K,T>::size() const {return elements.size();}

template<typename K, typename T>
T& Map<K,T>::operator[](const K& key) {
	Iterator it = elements.search(Entry(key));
	if(!it) {
		insert(key,T());
		it = elements.search(Entry(key));
	}
	return it->value;
}

template<typename K, typename T>
void Map<K,T>::insert(const K& key, const T& value) {
	elements.push(Entry(key,value));
	return;
}

template<typename K, typename T>
void Map<K,T>::erase(const K& key) {
	elements.remove(Entry(key));
	return;
}

template<typename K, typename T>
void Map<K,T>::swap(const Iterator& a, const Iterator& b) {
	T temp = a->value;
	a->value = b->value;
	b->value = temp;
	return;
}

template<typename K, typename T>
void Map<K,T>::clear() const {
	elements.clear();
	return;
}

template<typename K, typename T>
typename Map<K,T>::Iterator Map<K,T>::find(const K& key) const {
	return elements.search(Entry(key));
}

template<typename K, typename T>
typename Map<K,T>::Iterator Map<K,T>::begin() const {
	return elements.begin();
}

template<typename K, typename T>
typename Map<K,T>::Iterator Map<K,T>::end() const {
	return elements.end();
}

template<typename K, typename T>
typename Map<K,T>::Iterator Map<K,T>::rbegin() const {
	return elements.rbegin();
}

template<typename K, typename T>
typename Map<K,T>::Iterator Map<K,T>::rend() const {
	return elements.rend();
}

}//end namespace mystl

#endif










//
