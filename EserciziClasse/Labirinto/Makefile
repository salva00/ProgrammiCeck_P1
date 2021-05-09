CC = g++
STD = -std=c++11
OBJ = main.o

%.o: %.cpp
	$(CC) -c $< $(STD)
main: $(OBJ)
	$(CC) -o $^ $(STD)
	$(RM) $(OBJ)