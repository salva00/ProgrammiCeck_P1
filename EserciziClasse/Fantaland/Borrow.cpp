
#include "Borrow.h"
#include <iostream>

Borrow::Borrow(const Book& book, Date dat)
	: Book{book}, takedate{dat}, duedate{dat} {
	duedate.addMonth(1);
}

Borrow::Borrow(const Book& book, Date dat, Date due)
	: Book{book}, takedate{dat}, duedate{due} {}

bool Borrow::operator<(const Borrow& rhs) const {
	return this->duedate < rhs.duedate;
}

void Borrow::print() const {
	Book::print();
	std::cout << "      Was lent: " << static_cast<std::string>(takedate) << '\n';
	std::cout << "      due date: " << static_cast<std::string>(duedate) << '\n';
}

const Date& Borrow::getDue() const {
	return duedate;
}
