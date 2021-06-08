CFLAGS = -std=c++11 -pedantic -Wall
DEPS = TicTacToe.h
OBJ = TicTacToe.o main.o

main: $(OBJ)
	g++ -o $@ $^
%.o: %.cpp $(DEPS)
	g++ -c -o $@ $< $(CFLAGS)
