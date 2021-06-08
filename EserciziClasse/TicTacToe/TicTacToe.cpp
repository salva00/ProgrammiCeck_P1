
#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe() {
	for(short int i = 0; i < 9; ++i) {
		grid[i] = EMPTY;
	}
}

TicTacToe::mark TicTacToe::play() {
	for(short int i{0}; i < 9; ++i) {
		print();
		if(i % 2 == 0) {
			if(makeMove(CROSS)) {
				print();
				std::cout << "Cross wins!\n";
				return CROSS;
			}
		}	else {
			if(makeMove(CIRCLE)) {
				print();
				std::cout << "Circle wins!\n";
				return CIRCLE;
			}
		}
	}
	print();
	std::cout << "It's a draw\n";
	return EMPTY;
}
/*
7 -> 6 <-remap-> 0
8 -> 7 <-remap-> 1
9 -> 8 <-remap-> 2
4 -> 3 <-remap-> 3
5 -> 4 <-remap-> 4
6 -> 5 <-remap-> 5
1 -> 0 <-remap-> 6
2 -> 1 <-remap-> 7
3 -> 2 <-remap-> 8
*/
inline short int remap(short int i) {
	if(i < 3) i += 6;
	else if(i >= 6) i -= 6;
	return i;
}

bool TicTacToe::makeMove(const mark& m) {
	short int i;
	do {
		std::cout << "Make a move for " << (m==CROSS? "Cross": "Circle") << '\n';
		std::cin >> i;
		i = remap(i-1);
	} while (i < 0 || i > 9 || grid[i] != EMPTY);
	std::cout << '\n';
	grid[i] = m;
	if(checkWin(m)) return true;
	return 0;
}

/*0 1 2
	3 4 5
	6 7 8 */
bool TicTacToe::checkWin(const mark& m) {
	if(grid[0] == m) {
		if(grid[1] == m && grid[2] == m) return true;
		if(grid[3] == m && grid[6] == m) return true;
		if(grid[4] == m && grid[8] == m) return true;
	}
	if(grid[8] == m) {
		if(grid[2] == m && grid[5] == m) return true;
		if(grid[6] == m && grid[7] == m) return true;
	}
	if(grid[4] == m){
		if(grid[1] == m && grid[7] == m) return true;
		if(grid[3] == m && grid[5] == m) return true;
		if(grid[6] == m && grid[2] == m) return true;
	}
	return false;
}

/*0   | 1   | 2
    - |   - |   -
	----+-----+----
	3   | 4   | 5
	  - |   - |   -
	----+-----+----
	6   | 7   | 8
	  - |   - |   -
*/

void TicTacToe::print() const {
	system("cls");
	for(short int i{0}; i < 9; ++i) {
		if((i % 3) == 0)
			std::cout <<' '<<remap(i)+1<<"   | "<<remap(i)+2<<"   | "<<remap(i)+3<<'\n';
		std::cout << "   " << (grid[i]==CROSS? 'X':
									grid[i]==CIRCLE? 'O': '-') << " ";
		if(i == 2 || i == 5) std::cout << "\n-----+-----+-----\n";
		else if(i < 8) std::cout << "|";
		else std::cout << '\n';
	}
	return;
}

void TicTacToe::reset() {
	for(short int i{0}; i < 9; ++i) grid[i] = EMPTY;
	return;
}
