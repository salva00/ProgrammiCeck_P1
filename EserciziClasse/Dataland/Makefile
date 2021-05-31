CC=g++
CFLAGS=-std=c++11
DEPS = container.h customs.h
OBJ = container.o customs.o main.o
EXEC_NAME = main

 %.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
 $(EXEC_NAME): $(OBJ)
	$(CC) -o $@ $^
	erase $(OBJ)
