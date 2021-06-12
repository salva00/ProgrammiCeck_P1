CC=g++
CFLAGS=-std=c++11
DEPS= storage.h data.h
OBJ = main.o data.o storage.o

 %.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
 main: $(OBJ)
	$(CC) -o $@ $^
	erase $(OBJ)
