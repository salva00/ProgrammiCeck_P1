
#include <stdexcept>
#include <iostream>
#include <iomanip>

template<typename T>
class SparseMatrix {
public:
	class Node {
		friend class SparseMatrix;
	private:
		size_t row;
		size_t col;
		Node* right;
		Node* down;
		T value;
	public:
		Node(T,size_t,size_t,Node* = nullptr,Node* = nullptr);
		Node(size_t,size_t,Node* = nullptr,Node* = nullptr);
		~Node();
	};
private:
	Node* listrows{nullptr};
	Node* listcols{nullptr};
	size_t n; //rows
	size_t m; //cols
protected:
	Node* searchrow(size_t);
	Node* searchcol(size_t);
	void append(Node*);
	SparseMatrix<T>::Node* search(size_t,size_t) const;
public:
	SparseMatrix();
	SparseMatrix(const SparseMatrix<T>&);
	~SparseMatrix();
	void append(const T&, size_t, size_t);
	template<class Iterator> void load(const Iterator&, const Iterator&);
	T at(size_t,size_t) const;
	void set(const T&, size_t, size_t);
	void print();
	SparseMatrix<T> operator+(const SparseMatrix&) const;
};


// Node //

template<typename T>
SparseMatrix<T>::Node::Node(T val, size_t ro, size_t co, Node* r, Node* d) :
 	row{ro}, col{co}, right{r}, down{d}, value{val} {}

template<typename T>
SparseMatrix<T>::Node::Node(size_t ro, size_t co, Node* r, Node* d) :
 	row{ro}, col{co}, right{r}, down{d}, value{} {}

template<typename T>
SparseMatrix<T>::Node::~Node() {
	delete right;
	delete down;
	return;
}

// SparseMatrix //

template<typename T>
SparseMatrix<T>::SparseMatrix() : n{0}, m{0} {
}

template<typename T> //need rework
SparseMatrix<T>::SparseMatrix(const SparseMatrix<T>& rhs) : n{rhs.n}, m{rhs.m} {
	for(Node* i = rhs.listrows; i != nullptr; i = i->down) {
		for(Node* j = i->right; j != nullptr; j = j->right) {
			set(j->value, j->row, j->col);
		}
	}
}

template<typename T>
SparseMatrix<T>::~SparseMatrix() {delete listrows; delete listcols;}

template<typename T>
typename SparseMatrix<T>::Node* SparseMatrix<T>::searchrow(size_t r) {
	if(listrows == nullptr || listrows->row > r) {
		listrows = new Node(r,0,nullptr,listrows);
		return listrows;
	} else for(Node* it = listrows; it != nullptr; it = it->down) {
		if(it->row == r) return it;
		if(it->down == nullptr || it->down->row > r) {
			it->down = new Node(r,0,nullptr,it->down);
			return it->down;
		}
	}
	return nullptr;
}

template<typename T>
typename SparseMatrix<T>::Node* SparseMatrix<T>::searchcol(size_t c) {
	if(listcols == nullptr || listcols->col > c) {
		listcols = new Node(0,c,listcols,nullptr);
		return listcols;
	} else for(Node* it = listcols; it != nullptr; it = it->right) {
		if(it->col == c) return it;
		if(it->right == nullptr || it->right->col > c) {
			it->right = new Node(0,c,it->right,nullptr);
			return it->right;
		}
	}
	return nullptr;
}
/*
insert 0
X     !
X 2
X 0 2
X 1
*/
template<typename T>
void SparseMatrix<T>::append(const T& val, size_t r, size_t c) {
	Node* it = searchrow(r);
	Node* node;
	if(it->right == nullptr) {
		node = new Node(val,r,c);
		it->right = node;
	} else {
		while(it != nullptr) {
			if(it->right == nullptr) break; //it = last one
			if(it->right->col == c) return;
			if(it->right->col > c) break;
			it = it->right;
		}
		node = new Node(val,r,c,it->right,nullptr);
		it->right = node;
	}
	it = searchcol(c);
	if(it->down == nullptr) {
		it->down = node;
	} else {
		while(it != nullptr) {
			if(it->down == nullptr) break;
			if(it->down->row == r) return;
			if(it->down->row > r) break;
			it = it->down;
		}
		node->down = it->down;
		it->down = node;
	}
	if(++r > n) n = r;
	if(++c > m) m = c;
	return;
}

template<typename T>
void SparseMatrix<T>::append(Node* nodeptr) {
	append(nodeptr->value, nodeptr->row, nodeptr->col);
	return;
}

template<typename T> template<class Iterator>
void SparseMatrix<T>::load(const Iterator& begin, const Iterator& end) {
	Iterator it{begin};
	while(it != end) {
		append(*it);
		++it;
	}
	std::cout << '\n';
	return;
}

template<typename T>
typename SparseMatrix<T>::Node* SparseMatrix<T>::search(size_t r,size_t c) const {
	if(r <= c) {
		if(listrows == nullptr) {
			return nullptr;
		} else for(Node* it = listrows; it != nullptr; it = it->down) {
			if(it->row > r) return nullptr;
			if(it->row == r) {
				it = it->right;
				if(it == nullptr) return nullptr;
				while(it != nullptr) {
					if(it->col > c) return nullptr;
					if(it->col == c) return it;
					it = it->right;
				}
				return nullptr; //not found in col
			}
		}
		return nullptr; //not found in row
	} else {
		if(listcols == nullptr) {
			return nullptr;
		} else for(Node* it = listcols; it != nullptr; it = it->right) {
			if(it->col > c) return nullptr;
			if(it->col == c) {
				it = it->down;
				if(it == nullptr) return nullptr;
				while(it != nullptr) {
					if(it->row > r) return nullptr;
					if(it->row == r) return it;
					it = it->down;
				}
				return nullptr; //not found in rows
			}
		}
		return nullptr; //not found in col
	}
}

template<typename T>
T SparseMatrix<T>::at(size_t r, size_t c) const {
	Node* res = search(r,c);
	return res != nullptr ? res->value : T();
}

template<typename T>
void SparseMatrix<T>::set(const T& val, size_t r, size_t c) {
	Node* res = search(r,c);
	if(res == nullptr) append(val, r ,c);
	else res->value = val;
	return;
}

#define WD 3
#define CZERO "-"

inline void repeat(std::string str, size_t amt = 1) {
	for(int i = 0; i < amt; i++) std::cout << std::setw(WD) << str;
}

template<typename T>
void SparseMatrix<T>::print() {
	std::cout << n << "x" << m << '\n';
	size_t zcol = 0;
	size_t zrow = 0;
	// std::cout << "by rows:\n";
	for(Node* i = listrows; i != nullptr; i = i->down) {
		zcol = -1;
		for(int k = zrow+1; k < i->row && i->row - zrow > 1; k++) {
			std::cout << std::setw(WD) << std::right << k << ": ";
			repeat(CZERO, m);
			std::cout << '\n';
		}
		std::cout << std::setw(WD) << std::right << i->row << ": ";
		for(Node* j = i->right; j != nullptr; j = j->right) {
			if(j->col - zcol > 1) repeat(CZERO, j->col - zcol - 1);
			std::cout << std::setw(WD) << j->value;
			zcol = j->col;
		}
		if(m - zcol > 1) repeat(CZERO, m - zcol - 1);
		std::cout << "\n";
		zrow = i->row;
	}
	// std::cout << "by cols:\n";
	// for(Node* i = listcols; i != nullptr; i = i->right) {
	// 	std::cout << i->col << ": ";
	// 	for(Node* j = i->down; j != nullptr; j = j->down) {
	// 		std::cout << j->value << " ";
	// 	}
	// 	std::cout << "\n";
	// }
	return;
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::operator+(const SparseMatrix& rhs) const {
	SparseMatrix<T> res{rhs};
	Node* temp;
	for(Node* i = listrows; i != nullptr; i = i->down) {
		for(Node* j = i->right; j != nullptr; j = j->right) {
			temp = res.search(j->row,j->col);
			if(temp == nullptr) res.append(j->value, j->row, j->col);
			else temp->value += j->value;
		}
	}
	return res;
}










//
