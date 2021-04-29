CC=g++
CFLAGS=-std=c++11
DEPS= dictionary.h
OBJ= main.o dictionary.o

%.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o output $^
	erase $(OBJ)
	@echo Completed
