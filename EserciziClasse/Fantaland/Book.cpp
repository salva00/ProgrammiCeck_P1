
#include "Book.h"
#include <iostream>
#include <iomanip>

Book::Book(int id, std::string tit, int y, std::string pos, double val, std::vector<std::string> aut)
	: book_id{id}, title{tit}, year{y}, position{pos}, value{val}, authors{aut} {
	// TODO
	// setId(id);
	// setTitle(tit);
	// setYear(y);
	// setPosition(pos);
	//...
}

bool Book::operator<(const Book& rhs) const {
	// lhs minore di rhs se il suo autore viene prima in ordine
	// alfabetico, se sono uguali e' minore se e' stato scritto DOPO
	if(this->authors[0] == rhs.authors[0]) return this->year > rhs.year;
	else return this->authors[0] < rhs.authors[0];

}

bool Book::operator==(const Book& rhs) const {
	return this->book_id == rhs.book_id; // :(
}

int Book::getId() const {
	return this->book_id;
}

double Book::getValue() const {
	return this->value;
}

void Book::print() const {
	// stampa le specifiche del libro
	std::cout << std::left << std::setw(4) << book_id << ": " << std::setw(25)<< title << " (" << year
						<< ") " << std::setw(8) << position << " "<< value << "$\n";
	std::cout << "      Authors: ";
	for(auto aut : authors) {
		std::cout << aut << ", ";
	}
	std::cout << '\n';
	return;
}
