CC=g++
CFLAGS=-std=c++11
DEPS= BTS.h BTSNode.h
OBJ= main.o
EXEC_NAME=  bstTest

 %.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
 $(EXEC_NAME): $(OBJ)
	$(CC) -o $@ $^
	$(RM) $(OBJ)