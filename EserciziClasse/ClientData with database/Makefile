CC=g++
CFLAGS=-std=c++11 -pedantic -Wall
DEPS= clientdata.h clientdatabase.h
OBJ= main.o clientdata.o clientdatabase.o

%.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
output: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	erase $(OBJ)
	@echo Completed
