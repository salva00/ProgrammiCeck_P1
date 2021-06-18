
#ifndef BORROW_H
#define BORROW_H

#include "Book.h"
#include "Date.h"

class Borrow : public Book {
private:
	Date takedate;
	// giorno in cui si ha preso in
	// prestito il libro
	Date duedate;
	// giorno entro cui si deve
	// restituire il libro
public:
	Borrow(const Book& = Book(), Date = Date());
	// due date in automatico +1 mese
	Borrow(const Book&, Date, Date);
	// per una due date diversa

	bool operator<(const Borrow&) const;
	void print() const override;
	const Date& getDue() const;
};

#endif /* end of include guard: BORROW_H */
