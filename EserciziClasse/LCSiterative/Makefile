CFLAGS = -std=c++11 -Wall -pedantic
DEPS = lcs.h
OBJ = main.o

%.o: %.cpp $(DEPS)
	g++ -c $(CFLAGS) $<
main: $(OBJ)
	g++ -o main $(CFLAGS) $^
