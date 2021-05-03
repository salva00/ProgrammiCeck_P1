CC=g++
CFLAGS=-std=c++11
DEPS= Word.h
OBJ= main.o Word.o
EXE_NAME= dict
%.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $(EXE_NAME) $^
	${RM} $(OBJ)