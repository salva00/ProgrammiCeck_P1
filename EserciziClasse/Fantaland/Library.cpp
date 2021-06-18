
#include "Library.h"
#include <algorithm>
#include <iostream>

Library::Library() : books{}, lent{} {}

void Library::addBook(const Book& b) {
	// insert in order
	auto it = std::upper_bound(books.begin(),books.end(), b); // = primo valore maggiore di b
	if(it == books.end()) books.push_back(b);
	else books.insert(it, b);
}

void Library::borrowBook(int id, const Date& dat) {
	// search in books
	for(auto it = books.begin(); it != books.end(); ++it) {
		if(it->getId() == id) {
			lent.insert_in_order(Borrow(*it, dat));
			books.erase(it);
			return;
		}
	}
	throw std::invalid_argument("Book cannot be found");
	return;
}

void Library::borrowBook(const Book& b, const Date& dat) {
	borrowBook(b.getId(), dat);
	return;
}

double Library::returnBook(int id, const Date& dat) {
	// find match for id
	for(auto it = lent.begin(); it != lent.end(); ++it) {
		if(it->getId() == id) {
			double res = dat - it->getDue();
			addBook(Book(*it)); // downcast Borrow -> Book
			lent.erase(it);
			return res>0? res: 0;
		}
	}
	throw std::invalid_argument("Book cannot be found");
	return -1;
}

double Library::returnBook(const Book& b, const Date& dat) {
	return returnBook(b.getId(), dat);
}

void Library::print() const {
	std::cout << "Stored books:\n";
	if(books.empty()) std::cout << "-- Empty --\n";
	else for(Book b : books) b.print();
	std::cout << "Currently lent books:\n";
	if(lent.empty()) std::cout << "-- Empty --\n";
	else for(Borrow b : lent) b.print();
}

double Library::valueExpired(const Date& today) const {
	double res{0};
	for(auto it = lent.begin(); it != lent.end(); ++it) {
		if(it->getDue() < today) res += it->getValue();
	}
	return res;
}
