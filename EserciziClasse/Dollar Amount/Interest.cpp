#include <iostream>
#include <iomanip>
#include <string>
#include "DollarAmount.h"
using std::cout;
using std::cin;
using std::endl;
using std::setw;
int main() {
	DollarAmount d1{ 12345 };	//$123.45
	DollarAmount d2{ 1576 };	//$15.76

	cout << "After adding d2 (" << d2.toString() << ") into d1 ("
		<< d1.toString() << "), d1 = ";
	d1.add(d2);
	cout << d1.toString() << "\n";

	cout << "After subtracting d2 (" << d2.toString() << ") from d1 ("
		<< d1.toString() << "), d1 = ";
	d2.subtract(d1);
	cout << d2.toString() << "\n";

	cout << "Enter integer interest rate and divisor. For example:\n"
		<< "for			2%,	enter:		2	100\n"
		<< "for		  2.3%,	enter:	   23	1000\n"
		<< "for		 2.37%,	enter:	  273	10000\n"
		<< "for		2.375%,	enter:	 2375	100000\n ";
	int rate;
	int divisor;
	cin >> rate >> divisor;

	DollarAmount balance{ 100000 };
	cout << "\nInitial balance: " << balance.toString() << endl;

	cout << "\nYear" << std::setw(20) << "Amount on deposit" << endl;

	for (unsigned int year{ 1 }; year <= 10; year++) {
		balance.adddInterest(rate, divisor);
		cout << setw(4) << year << setw(20) << balance.toString() << endl;
	}
}