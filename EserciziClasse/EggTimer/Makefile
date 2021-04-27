CFLAGS = -Wall -pedantic -std=c++11

output: eggtimer.o main.o
	g++ -o output ${CFLAGS} $^
	erase -f *.o
	@echo Completed
eggtimer.o: eggtimer.cpp eggtimer.h
	g++ -c ${CFLAGS} $<
main.o: main.cpp eggtimer.h
	g++ -c ${CFLAGS} $<
