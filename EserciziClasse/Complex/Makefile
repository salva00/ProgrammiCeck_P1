CC=g++
CFLAGS=-std=c++11
DEPS= Complex.h
OBJ= main.o Complex.o
EXEC_NAME= main

 %.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
 $(EXEC_NAME): $(OBJ)
	$(CC) -o $@ $^
