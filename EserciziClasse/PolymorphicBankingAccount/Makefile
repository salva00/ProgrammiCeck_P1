CFLAGS = -Wall -pedantic -std=c++11

DEPS = Account.h CheckingAccount.h SavingsAccount.h
OBJ = Account.o CheckingAccount.o SavingsAccount.o main.o

%.o: %.cpp ${DEPS}
	g++ -c ${CFLAGS} -o $@ $<
output: ${OBJ}
	g++ -o output ${CFLAGS} $^
	erase ${OBJ}
	@echo Completed
