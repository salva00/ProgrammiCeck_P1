GCC=g++
CFLAGS=-std=c++11
DEPS=*.h
OBJ= test.o
EXEC_NAME=test

 %.o: %.cpp $(DEPS)
	$(GCC) -c $< $(CFLAGS)
 $(EXEC_NAME): $(OBJ)
	$(GCC) -o $@ $^
	erase $(OBJ)
