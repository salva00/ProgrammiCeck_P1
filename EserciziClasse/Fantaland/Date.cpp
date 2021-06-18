
#include "Date.h"

Date::Date(int y, int m, int d) {
	setYear(y);
	setMonth(m);
	setDay(d);
}

// 2000/12/12
Date::Date(std::string str) {
	if(str.size() != 10) throw std::invalid_argument("Invalid string date format");
	for(char c : str) if(c != '/' && (c > '9' || c < '0')) throw std::invalid_argument("Invalid string date format");
	setYear(std::stoi(str.substr(0,4)));
	setMonth(std::stoi(str.substr(5,2)));
	setDay(std::stoi(str.substr(8,2)));
}

void Date::setDay(int d) {
	if(d < 0 || d > 31) throw std::invalid_argument("Incorrect day format");
	else day = d;
}

void Date::setMonth(int m) {
	if(m < 0 || m > 12) throw std::invalid_argument("Incorrect month format");
	else month = m;
}

void Date::setYear(int y) {
	if(y < 0 || y > 9999) throw std::invalid_argument("Incorrect year format");
	else year = y;
}

unsigned short Date::getDay() const {return this->day;}
unsigned short Date::getMonth() const {return this->month;}
unsigned short Date::getYear() const {return this->year;}

bool Date::operator<(const Date& rhs) const {
	return year<rhs.year?
		1:(year==rhs.year?
			(month<rhs.month?
				 1:(month==rhs.month?
					 (day<rhs.day):0))
			:0);
}

Date::operator std::string() const {
	std::string res;
	res += std::to_string(year) + '/';
	if(month < 10) res += '0';
	res += std::to_string(month) + '/';
	if(day < 10) res += '0';
	res += std::to_string(day);
	return res;
}

void Date::addMonth(int amt) {
	if(this->month >= 12) {
		++year;
		month = 1;
	} else {
		++month;
	}
	return;
}

int Date::operator-(const Date& rhs) const {
	if(*this < rhs) return -1;
	int y, m, d;
	y = this->year - rhs.year;
	if(this->month > rhs.month) {
		//2021/08 - 2020/10
		m = this->month - rhs.month;
	} else {
		m = 12 + rhs.month - this->month;
		--y;
	}
	if(this->day > rhs.day) {
		//2021/08 - 2020/10
		d = this->day - rhs.day;
	} else {
		d = 31 + rhs.day - this->day;
		--m;
	}
	return d + (31*m) + (365*y);
}
