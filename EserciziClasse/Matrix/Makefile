
CFLAGS = -Wall -pedantic -std=c++11

output: matrix.o main.o
	g++ -o output ${CFLAGS} $^
	erase -f *.o
	@echo Completed
matrix.o: matrix.cpp matrix.h
	g++ -c ${CFLAGS} $<
main.o: main.cpp matrix.h
	g++ -c ${CFLAGS} $<
