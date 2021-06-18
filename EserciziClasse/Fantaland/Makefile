CC=g++
CFLAGS=-std=c++11
DEPS= Book.h Borrow.h Date.h Library.h
OBJ= main.o Book.o Borrow.o Date.o Library.o

%.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^
