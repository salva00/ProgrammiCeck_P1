
#ifndef DATE_H
#define DATE_H

#include <string>
#include <stdexcept>

class Date {
private:
	unsigned short year;
	unsigned short month;
	unsigned short day;
public:
	Date(int = 1, int = 1, int = 1);
	Date(std::string);
	void setDay(int);
	void setMonth(int);
	void addMonth(int);
	void setYear(int);
	unsigned short getDay() const;
	unsigned short getMonth() const;
	unsigned short getYear() const;
	bool operator<(const Date&) const;
	operator std::string() const;
	int operator-(const Date&) const;
};
#endif














//
