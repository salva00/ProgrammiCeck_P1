
#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
public:
	enum mark{EMPTY, CROSS, CIRCLE};
private:
	mark grid[9];
protected:
	bool checkWin(const mark&);
	bool makeMove(const mark&);
public:
	TicTacToe();
	void print() const;
	void reset();
	mark play();
};

#endif
