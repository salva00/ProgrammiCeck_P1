CC=g++
STD=-std=c++11
DEPS=LinkedList.h Node.h ListStack.h
EXE_NAME = testListStack
OBJ = main.o
%.o: %.cpp	$(DEPS)
	$(CC) -c $< $(STD)
$(EXE_NAME): $(OBJ)
	$(CC) -o $@ $^
	$(RM) $(OBJ)