CC=g++
CFLAGS=-std=c++11
DEPS= {.h files}
OBJ= {.o files}
EXEC_NAME=  {name of executable file}

 %.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
 $(EXEC_NAME): $(OBJ)
	$(CC) -o $@ $^
	$(RM) $(OBJ)
