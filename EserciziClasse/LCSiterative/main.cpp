
#include <iostream>
#include "lcs.h"


int main() {

	std::string str1 = "ATACCAGA";
	std::string str2 = "CTCCTAG";

/*
- - C T C C T A G
- 0 0 0 0 0 0 0 0
A 0 0 0 0 0 0 1 1
T 0 0 1 1 1 1 1 1
A 0 0 1 1 1 1 2 2
C 0 1 1 2 2 2 2 2
C 0 1 1 2 3 3 3 3
A 0 1 1 2 3 3 4 4
G 0 1 1 2 3 3 4 5
A 0 1 1 2 3 3 4 5
*/
	std::cout << "LCS is " << lcs(str1,str2) << '\n';
	system("pause");
	return 0;
}
