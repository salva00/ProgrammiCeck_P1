
#ifndef LIBRARY_H
#define LIBRARY_H

#include "Borrow.h"
#include "..\lib\mystl\DoublyLinkedList.h"

class Library {
private:
	std::vector<Book> books;
	mystl::DLinkedList<Borrow> lent;
public:
	Library();
	void addBook(const Book&);
	// aggiunge un libro alla libreria
	void borrowBook(int, const Date&);
	void borrowBook(const Book&, const Date&);
	// sposta un libro da books a lent
	double returnBook(int, const Date&);
	double returnBook(const Book&, const Date&);
	// sposta un libro da lent a books

	// deleteBook(); TODO
	void print() const;
	double valueExpired(const Date&) const;

};



#endif /* end of include guard: LIBRARY_H */
