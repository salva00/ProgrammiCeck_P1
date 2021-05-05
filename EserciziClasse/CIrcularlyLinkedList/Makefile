CC=g++
STD=-std=c++11
DEPS= Cnode.h CircularlyLinkedList.h
OBJ = main.o
EXE_NAME = testCircularlyLinkedList

%.o: %.cpp	$(DEPS)
	$(CC) -c $< $(STD)

$(EXE_NAME): $(OBJ)
	$(CC) -o $@ $^ $(STD)
	$(RM) $(OBJ)
