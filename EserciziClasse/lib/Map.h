
#ifndef MAP_H
#define MAP_H

#include "BinarySearchTree.h"

namespace mystl {

template<typename K, typename T> class Map;

template<typename K, typename T>
class Entry {
	friend class Map<K,T>;
protected:
	Entry(const K, const T = T());
public:
	K key;
	T value;
	bool operator<(const Entry&) const;
	bool operator==(const Entry&) const;
};

template<typename K, typename T>
// K requires operator< and operator==
class Map : private BinarySearchTree<Entry<K,T>> {
private:
	using Container = BinarySearchTree<Entry<K,T>>;
public:
	using Iterator = typename Container::Iterator;
	using ConstIterator = typename Container::ConstIterator;

	//
	Map();
	Map(const Map&);
	~Map();
	// default constructor
	bool empty() const;
	// returns true if empty
	size_t size() const;
	// // returns size
	const T& at(const K&) const;
	// access elements
	void insert(const K&, const T&);
	// insert elments
	T& operator[](const K&);
	// access elements/ create new element
	void erase(const K&);
	// delete element with key #1
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
	ConstIterator cbegin() const;
	// return const iterator to begin
	ConstIterator cend() const;
	// return const iterator to end
	ConstIterator crbegin() const;
	// return const iterator to reverse begin
	ConstIterator crend() const;
	// return const iteratro to rever end
	void clear();
	// deletes all stored data
};



// Entry //

template<typename K, typename T>
Entry<K,T>::Entry(const K k, const T val) : key{k}, value{val} {}

template<typename K, typename T>
bool Entry<K,T>::operator<(const Entry& rhs) const {
	return this->key < rhs.key;
}

template<typename K, typename T>
bool Entry<K,T>::operator==(const Entry& rhs) const {
	return this->key == rhs.key;
}

// Map //

template<typename K, typename T>
Map<K,T>::Map() : Container::BinarySearchTree() {}

template<typename K, typename T>
Map<K,T>::Map(const Map& map) : Container::BinarySearchTree(map) {}

template<typename K, typename T>
Map<K,T>::~Map() {
	Container::~BinarySearchTree();
}

template<typename K, typename T>
bool Map<K,T>::empty() const {
	return Container::empty();
}

template<typename K, typename T>
size_t Map<K,T>::size() const {
	return Container::size();
}


template<typename K, typename T>
T& Map<K,T>::operator[](const K& key) {
	Iterator it = Container::search(Entry<K,T>(key));
	if(!it) {
		insert(key,T());
		it = Container::search(Entry<K,T>(key));
	}
	return it->value;
}

template<typename K, typename T>
void Map<K,T>::insert(const K& key, const T& value) {
	Container::push(Entry<K,T>(key,value));
	return;
}

template<typename K, typename T>
void Map<K,T>::erase(const K& key) {
	Container::remove(Entry<K,T>(key));
	return;
}

template<typename K, typename T>
void Map<K,T>::clear() const {
	Container::clear();
	return;
}

template<typename K, typename T>
typename Map<K,T>::Iterator Map<K,T>::find(const K& key) const {
	return Container::search(Entry<K,T>(key));
}

template<typename K, typename T>
typename Map<K,T>::Iterator Map<K,T>::begin() const {
	return Container::begin();
}

template<typename K, typename T>
typename Map<K,T>::Iterator Map<K,T>::end() const {
	return Container::end();
}

template<typename K, typename T>
typename Map<K,T>::Iterator Map<K,T>::rbegin() const {
	return Container::rbegin();
}

template<typename K, typename T>
typename Map<K,T>::Iterator Map<K,T>::rend() const {
	return Container::rend();
}

template<typename K, typename T>
typename Map<K,T>::ConstIterator Map<K,T>::cbegin() const {
	return Container::cbegin();
}

template<typename K, typename T>
typename Map<K,T>::ConstIterator Map<K,T>::cend() const {
	return Container::cend();
}

template<typename K, typename T>
typename Map<K,T>::ConstIterator Map<K,T>::crbegin() const {
	return Container::crbegin();
}

template<typename K, typename T>
typename Map<K,T>::ConstIterator Map<K,T>::crend() const {
	return Container::crend();
}

template<typename K, typename T>
void Map<K,T>::clear() {
	Container::clear();
	return;
}

}//end namespace mystl

#endif










//
