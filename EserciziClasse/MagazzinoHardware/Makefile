CC=g++
CFLAGS=-std=c++11
DEPS= main.cpp Articoli.h Articoli.cpp
OBJ= main.o Articoli.o
EXEC_NAME=main

 %.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
 $(EXEC_NAME): $(OBJ)
	$(CC) -o $@ $^
	$(RM) $(OBJ)