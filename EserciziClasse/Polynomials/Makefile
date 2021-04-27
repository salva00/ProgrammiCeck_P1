CFLAGS = -Wall -pedantic -std=c++11

output: polynomials.o main.o
	g++ -o output ${CFLAGS} $^
	erase -f *.o
	@echo Completed
polynomials.o: polynomials.cpp polynomials.h
	g++ -c ${CFLAGS} $<
main.o: main.cpp polynomials.h
	g++ -c ${CFLAGS} $<
