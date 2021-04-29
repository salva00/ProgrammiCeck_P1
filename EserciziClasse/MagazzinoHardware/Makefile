CC=g++
 CFLAGS=-std=c++11
 DEPES= main.cpp Articoli.h Articoli.cpp
 OBJ= main.o Articoli.o

 %.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
 main: $(OBJ)
	$(CC) -o $@ $^