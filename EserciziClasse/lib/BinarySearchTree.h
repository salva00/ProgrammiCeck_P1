
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream> // DEBUG

namespace mystl {

template<typename T>
// T requires operator< and operator==
class BinarySearchTree {
private:
	class Node {
		friend class BinarySearchTree;
		private:
		T value;
		Node* parent;
		Node* lchild;
		Node* rchild;
		Node(T, Node* = nullptr, Node* = nullptr, Node* = nullptr);
		~Node();
	};
public:
	class Iterator {
		friend class BinarySearchTree;
		private:
		Iterator(Node* = nullptr);
		Node* point;
		public:
		using iterator_category = std::bidirectional_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;
		T& operator*() const;
		T* operator->() const;
		Iterator& operator++();
		Iterator operator++(int);
		// jumps to successor
		Iterator& operator--();
		Iterator operator--(int);
		// jumps to predecessor
		bool operator==(const Iterator&) const;
		bool operator!=(const Iterator&) const;
		operator bool() const;
	};
protected:
	void preorderCopy(Node*, Node*, const BinarySearchTree<T>* const);
	// user by copy constructor
	void remove(Node*);
	// used by remove(iterator) and remove(T)
	static Node* successor(Node*);
	// used for iteration
	static Node* predecessor(Node*);
	// used for iteration
	Node* replacenode(Node*, Node*);
	// replace #1 with #2, does not detach #2 !!!
	inline bool isLchild(Node*) const;
	// nullptr exception if #1 is root
	void unsafeDel(Node*);
	// detach node, then delete
	Node* balance(Node**,size_t,size_t);
	void balance();
	// rearrange nodes in unbalanced tree
private:
	Node* root;
	// root of the tree
	size_t n;
	// number of elements stored
	size_t leaves;
	// number of leaf nodes
	Node* max;
	// node which cointains maximum value
	Node* min;
	// node which cointains minimum value
public:
	BinarySearchTree();
	// default constructor
	~BinarySearchTree();
	// deletes all nodes
	BinarySearchTree(const BinarySearchTree<T>&);
	// copy constructor
	BinarySearchTree<T>& operator=(const BinarySearchTree<T>&);
	// copy assignment
	void push(const T&);
	// pushes node at the bottom
	const T& getMin() const;
	// returns minimum value stored
	const T& getMax() const;
	// returns maximum value stored
	size_t getLeaves() const;
	// returns number of leaf nodes
	bool empty() const;
	// returns true if empty
	size_t size() const;
	// returns number of elements stored
	Iterator search(const T&) const;
	// returns iterator to value #1
	void remove(const T&);
	// removes node with value #1
	Iterator remove(const Iterator&);
	// removes node pointed by iterator
	void clear();
	// deletes all nodes
	Iterator begin() const;
	// returns iterator to begin (minimum element)
	Iterator end() const;
	// returns iterator after end (maximum)
	Iterator rbegin() const;
	// returns iterator to end (maximum)
	Iterator rend() const;
	// return iterator before begin (minimum)
	// N.B. iterating begin->end is O(n)

	// DEBUG - remember to uncomment implementation and dependencies
	// void print(const std::string&, const Node*, bool) const;
	// void print(const Node*) const;
	// void print() const;
};



// Node //

template<typename T>
BinarySearchTree<T>::Node::Node(T val, Node* par, Node* lch, Node* rch)
	: value{val}, parent{par}, lchild{lch}, rchild{rch} {}

template<typename T>
BinarySearchTree<T>::Node::~Node() {
	delete lchild, delete rchild;
}

// Iterator //

template<typename T>
BinarySearchTree<T>::Iterator::Iterator(Node* p) : point{p} {}

template<typename T>
T& BinarySearchTree<T>::Iterator::operator*() const {return point->value;}

template<typename T>
T* BinarySearchTree<T>::Iterator::operator->() const {return &point->value;}

template<typename T>
bool BinarySearchTree<T>::Iterator::operator==(const Iterator& rhs) const {
	return this->point == rhs.point;
}

template<typename T>
bool BinarySearchTree<T>::Iterator::operator!=(const Iterator& rhs) const {
	return this->point != rhs.point;
}

template<typename T>
typename BinarySearchTree<T>::Iterator& BinarySearchTree<T>::Iterator::operator++() {
	point = BinarySearchTree<T>::successor(point);
	return *this;
}

template<typename T>
typename BinarySearchTree<T>::Iterator BinarySearchTree<T>::Iterator::operator++(int) {
	Iterator temp = *this;
	this->operator++();
	return temp;
}

template<typename T>
typename BinarySearchTree<T>::Iterator& BinarySearchTree<T>::Iterator::operator--() {
	point = BinarySearchTree<T>::predecessor(point);
	return *this;
}

template<typename T>
typename BinarySearchTree<T>::Iterator BinarySearchTree<T>::Iterator::operator--(int) {
	Iterator temp = *this;
	this->operator--();
	return temp;
}

template<typename T>
BinarySearchTree<T>::Iterator::operator bool() const {
	return point != nullptr;
}

// BinarySearchTree //

template<typename T>
BinarySearchTree<T>::BinarySearchTree() : root{nullptr}, n{0}, leaves{0} {}

template<typename T>
void BinarySearchTree<T>::preorderCopy(Node* l_ptr, Node* r_ptr, const BinarySearchTree<T>* const rhs) {
	if(r_ptr != nullptr) {
		// this->print();
		while(l_ptr->value != r_ptr->parent->value) {
			l_ptr = l_ptr->parent;
		}
		if(isLchild(r_ptr)) {
			l_ptr->lchild = new Node(r_ptr->value, l_ptr);
			l_ptr = l_ptr->lchild;
		} else {
			l_ptr->rchild = new Node(r_ptr->value, l_ptr);
			l_ptr = l_ptr->rchild;
		}
		if(l_ptr == rhs->max) this->max = l_ptr;
		if(l_ptr == rhs->min) this->min = l_ptr;
		preorderCopy(l_ptr, r_ptr->lchild, rhs);
		preorderCopy(l_ptr, r_ptr->rchild, rhs);
	}
	return;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& rhs)
	: n{rhs.n}, leaves{rhs.leaves} {

	if(!rhs.empty()) {
		this->root = new Node(rhs.root->value);
		preorderCopy(this->root, rhs.root->lchild, &rhs);
		preorderCopy(this->root, rhs.root->rchild, &rhs);
	} else {
		this->root = nullptr;
		min = nullptr;
		max = nullptr;
	}
}

template<typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T>& tree) {
	clear();
	BinarySearchTree<T> temp{tree};
	this->root = temp.root;
	this->n = temp.n;
	this->leaves = temp.leaves;
	this->max = temp.max;
	this->min = temp.min;
	temp.root = nullptr;
	return *this;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
	delete root;
}

template<typename T>
void BinarySearchTree<T>::push(const T& val) {
	if(root == nullptr) {
		root = new Node(val);
		leaves = 1, ++n;
		min = root;
		max = root;
		return;
	} else {
		Node* ptr{root};
		bool isMin{true}, isMax{true};
		while(ptr != nullptr) {
			if(val == ptr->value) throw std::invalid_argument("Duplicates are not allowed");

			if(val < ptr->value) {
				isMax = false;
				if(ptr->lchild == nullptr) {
					ptr->lchild = new Node(val,ptr);
					if(isMin) min = ptr->lchild;
					if(ptr->rchild != nullptr) ++leaves;
					++n;
					break;
				}
				ptr = ptr->lchild;
			}
			else {
				isMin = false;
				if(ptr->rchild == nullptr) {
					ptr->rchild = new Node(val,ptr);
					if(isMax) max = ptr->rchild;
					if(ptr->lchild != nullptr) ++leaves;
					++n;
					break;
				}
				ptr = ptr->rchild;
			}
		}
	}
	if(leaves*4 < n) balance();
	return;
}

template<typename T>
inline bool BinarySearchTree<T>::isLchild(Node* node) const {
	return node->parent->lchild == node;
}

template<typename T>
void BinarySearchTree<T>::unsafeDel(Node* ptr) {
	ptr->parent = nullptr;
	ptr->lchild = nullptr;
	ptr->rchild = nullptr;
	delete ptr;
	return;
}

template<typename T>
const T& BinarySearchTree<T>::getMax() const {
	if(max == nullptr) throw std::runtime_error("Tree empty");
	return max->value;
}

template<typename T>
const T& BinarySearchTree<T>::getMin() const {
	if(min == nullptr) throw std::runtime_error("Tree empty");
	return min->value;
}

template<typename T>
size_t BinarySearchTree<T>::getLeaves() const {
	return leaves;
}

template<typename T>
bool BinarySearchTree<T>::empty() const {
	return root == nullptr;
}

template<typename T>
size_t BinarySearchTree<T>::size() const {
	return n;
}

template<typename T>
typename BinarySearchTree<T>::Iterator BinarySearchTree<T>::search(const T& val) const {
	Iterator it{root};
	while(it.point != nullptr) {
		// std::cout << *it << '\n';
		if(*it == val) return it;
		if(*it < val) it.point = it.point->rchild;
		else it.point = it.point->lchild;
	}
	it.point = nullptr;
	return it;
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::successor(Node* ptr) {
	if(ptr->rchild != nullptr) {
		ptr = ptr->rchild;
		while(ptr->lchild != nullptr) {
			ptr = ptr->lchild;
		}
	} else {
		Node* par = ptr->parent;
		while(par != nullptr && ptr == par->rchild) {
			ptr = par;
			par = ptr->parent;
		}
		ptr = par;
	}
	return ptr;
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::predecessor(Node* ptr) {
	if(ptr->lchild != nullptr) {
		ptr = ptr->lchild;
		while(ptr->rchild != nullptr) {
			ptr = ptr->rchild;
		}
	} else {
		Node* par = ptr->parent;
		while(par != nullptr && ptr == par->lchild) {
			ptr = par;
			par = ptr->parent;
		}
		ptr = par;
	}
	return ptr;
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::replacenode(Node* rplment, Node* torpl) {
	if(torpl->parent != nullptr) {
		(isLchild(torpl)? torpl->parent->lchild : torpl->parent->rchild) = rplment;
	}
	if(torpl->lchild != nullptr) torpl->lchild->parent = rplment;
	if(torpl->rchild != nullptr) torpl->rchild->parent = rplment;
	rplment->parent = torpl->parent;
	rplment->lchild = torpl->lchild;
	rplment->rchild = torpl->rchild;
	if(torpl == root) root = rplment;
	return torpl;
}

template<typename T>
void BinarySearchTree<T>::remove(Node* ptr) {
	// Node *replace{nullptr}, *child{nullptr};
	// if(ptr->lchild == nullptr || ptr->rchild == nullptr) {
	// 	replace = ptr;
	// } else replace = BinarySearchTree<T>::successor(replace);
	// if(replace->lchild != nullptr) child = replace->lchild;
	// else child = replace->rchild;
	// if(child != nullptr) child->parent = replace->parent;
	// if(replace->parent = nullptr) {
	// 	this->root = child;
	// } else {
	// 	if(replace == replace->parent->lchild) child = replace->parent->lchild;
	// 	else child = replace->parent->rchild;
	// }
	// if(replace != ptr) {
	// 	replacenode(replace,ptr);
	// }
	// std::cout << ptr->value << '\n';
	if(ptr == min) min = successor(ptr);
	if(ptr == max) max = predecessor(ptr);
	if(ptr->lchild != nullptr && ptr->rchild != nullptr) {
		// std::cout << "2 children\n";
		Node* succ = successor(ptr);
		if(succ->lchild == nullptr && succ->rchild == nullptr) --leaves;
		(isLchild(succ)? succ->parent->lchild : succ->parent->rchild) = succ->rchild;
		if(succ->rchild != nullptr) succ->rchild->parent = succ->parent;
		replacenode(succ,ptr);
	} else if(ptr->lchild == nullptr && ptr->rchild == nullptr) {
		// std::cout << "0 children\n";
		if(ptr->parent != nullptr) {
			if(ptr->parent->rchild != nullptr && ptr->parent->lchild != nullptr) --leaves;
			(isLchild(ptr)? ptr->parent->lchild : ptr->parent->rchild) = nullptr;
			}
		else {
			root = nullptr;
			max = nullptr;
			min = nullptr;
			leaves = 0;
		}
	} else {
		// std::cout << "1 child\n";
		Node* child = (ptr->lchild != nullptr? ptr->lchild : ptr->rchild);
		if(ptr->parent == nullptr) {
			root = child;
		} else if(isLchild(ptr)) {
			ptr->parent->lchild = child;
		} else {
			ptr->parent->rchild = child;
		}
		child->parent = ptr->parent;
		//no effect on leaves
	}
	--n;
	unsafeDel(ptr);
	return;
}

template<typename T>
typename BinarySearchTree<T>::Iterator BinarySearchTree<T>::remove(const Iterator& it) {
	Iterator res{it};
	++res;
	remove(it.point);
	return res;
}

template<typename T>
void BinarySearchTree<T>::remove(const T& val) {
	Iterator it = search(val);
	if(it->point != nullptr) remove(it);
	else throw std::runtime_error("Search failed");
	return;
}

template<typename T>
void BinarySearchTree<T>::clear() {
	delete root;
	leaves = 0;
	n = 0;
	max = nullptr, min = nullptr;
	root = nullptr;
	return;
}

template<typename T>
typename BinarySearchTree<T>::Iterator BinarySearchTree<T>::begin() const {
	return (empty()? Iterator(nullptr): Iterator(min));
}

template<typename T>
typename BinarySearchTree<T>::Iterator BinarySearchTree<T>::end() const {
	return Iterator(nullptr);
}

template<typename T>
typename BinarySearchTree<T>::Iterator BinarySearchTree<T>::rbegin() const {
	return Iterator(max);
}

template<typename T>
typename BinarySearchTree<T>::Iterator BinarySearchTree<T>::rend() const {
	return Iterator(nullptr);
}

template<typename T>
void BinarySearchTree<T>::balance() {
	if(n < 3) return;
	Node* arr[n];
	Iterator it{begin()};
	for(size_t j = 0; it != end(); ++it, ++j) {
		arr[j] = it.point;
	}
	leaves = 0;
	root = balance(arr,0,n-1);
	root->parent = nullptr;
	return;
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::balance(Node** arr, size_t begin, size_t end) {
	if(begin < end) {
		size_t mid = (begin+end)/2;
		// std::cout << "at " << arr[mid]->value << '\n';
		if(mid == begin) {
			arr[mid]->lchild = nullptr;
		} else {
			arr[mid]->lchild = balance(arr,begin,mid-1);
			arr[mid]->lchild->parent = arr[mid];
		}
		// std::cout << arr[mid]->value << "->lchild = " << ((arr[mid]->lchild==nullptr)?-1:arr[mid]->lchild->value) << '\n';
		if(mid == end) {
			arr[mid]->rchild = nullptr;
		} else {
			arr[mid]->rchild = balance(arr,mid+1,end);
			arr[mid]->rchild->parent = arr[mid];
		}
		// std::cout << arr[mid]->value << "->rchild = " << ((arr[mid]->rchild==nullptr)?-1:arr[mid]->rchild->value) << '\n';
		return arr[mid];
	} else if(begin == end) {
		++leaves;
		arr[begin]->lchild = nullptr;
		arr[begin]->rchild = nullptr;
		return arr[begin];
	} else {
		throw;
	}
}

//DEBUG

// template<typename T>
// void BinarySearchTree<T>::print(const std::string& prefix, const Node* node, bool isLeft) const {
// 	if( node != nullptr ) {
// 		std::cout << prefix;
// 		std::cout << (isLeft ? (char)195 : (char)192) << "--";
// 		std::cout << ' ' << node->value << '\n';
// 		print(prefix + (isLeft ? "|   " : "    "), node->lchild, true);
// 		print(prefix + (isLeft ? "|   " : "    "), node->rchild, false);
// 	}
// 	return;
// }
//
// template<typename T>
// void BinarySearchTree<T>::print(const Node* node) const {
// 	print("", node, false);
// }
//
// template<typename T>
// void BinarySearchTree<T>::print() const {
// 	if(empty()) std::cout << "tree empty\n";
// 	else print("", root, false);
// }


}//end namespace mystl

#endif
