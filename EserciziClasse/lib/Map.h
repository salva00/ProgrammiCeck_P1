
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
	//
	Map();
	// default constructor
	Map(const Map&);
	// copy constructor
	Map& operator=(const Map&);
	// copy assignment
	~Map() = default;
	// destructor
	bool empty() const;
	// returns true if empty
	size_t size() const;
	// // returns size
	const T& at(const K&) const;
	// access elements
	Iterator insert(const K&, const T&);
	// insert elments
	T& operator[](const K&);
	// access elements/ create new element
	void erase(const K&);
	// delete element with key #1
	Iterator erase(const Iterator&);
	// delete element pointed by iterator
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
	// return iterator to rever end
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
Map<K,T>& Map<K,T>::operator=(const Map& rhs) {
	Container::operator=(rhs);
	return *this;
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
const T& Map<K,T>::at(const K& key) const {
	Iterator it = Container::find(Entry<K,T>(key));
	if(!it) throw std::invalid_argument("Key cannot be found");
	else return it->value;
}

template<typename K, typename T>
typename Map<K,T>::Iterator Map<K,T>::insert(const K& key, const T& value) {
	return Container::insert(Entry<K,T>(key,value));
}

template<typename K, typename T>
T& Map<K,T>::operator[](const K& key) {
	Iterator it = Container::find(Entry<K,T>(key));
	if(!it) {
		insert(key,T());
		it = Container::find(Entry<K,T>(key));
	}
	return it->value;
}

template<typename K, typename T>
void Map<K,T>::erase(const K& key) {
	Container::erase(Entry<K,T>(key));
	return;
}

template<typename K, typename T>
typename Map<K,T>::Iterator Map<K,T>::erase(const Iterator& it) {
	return Container::erase(it);
}

template<typename K, typename T>
void Map<K,T>::clear() const {
	Container::clear();
	return;
}

template<typename K, typename T>
typename Map<K,T>::Iterator Map<K,T>::find(const K& key) const {
	return Container::find(Entry<K,T>(key));
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
void Map<K,T>::clear() {
	Container::clear();
	return;
}

}//end namespace mystl

#endif










//
