
#ifndef BOOK_H
#define BOOK_H

#include <vector>
#include <string>

class Book {
private:
	int book_id;
	std::string title;
	int year;
	std::string position;
	double value;
	std::vector<std::string> authors;
public:
	Book(int = 0, std::string = "none", int = 2000, std::string = "0000", double = 0.0, std::vector<std::string> = std::vector<std::string>());
	bool operator<(const Book&) const;
	bool operator==(const Book&) const;
	int getId() const;
	double getValue() const;
	/*
	getters/setters
	...
	*/
	virtual void print() const;
};

#endif /* end of include guard: BOOK_H */
