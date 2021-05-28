CC= g++
STD = -std=c++11
DEPS = Dnode.h LinkedList.h
OBJ = main.o
EXE_NAME = testDoubleList

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(STD)

$(EXE_NAME): $(OBJ)
	$(CC) -o $@ $^ $(STD)
