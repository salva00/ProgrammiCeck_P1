CC = g++
CFLAGS = -std=c++11 -pedantic -Wall
DEPS = ArrayQueue.h
OBJ = main.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)