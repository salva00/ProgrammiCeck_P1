CC=g++
CFLAGS=-std=c++11
DEPES= main.cpp Account.h Account.cpp SavingsAccount.h SavingsAccount.cpp CheckingAccount.h CheckingAccount.cpp
OBJ= Account.o main.o SavingsAccount.o CheckingAccount.o

%.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^