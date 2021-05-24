CC=g++
CFLAGS=-std=c++11
DEPS= LinkedList.h Node.h
OBJ= main.o
EXEC_NAME= splitList

 %.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
 $(EXEC_NAME): $(OBJ)
	$(CC) -o $@ $^
	$(RM) $(OBJ)