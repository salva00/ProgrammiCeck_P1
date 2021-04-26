STD = c++11
FLAGS = -pedantic -Wall

main: main.o
	g++ -o main main.o
main.o: main.cpp Account.h
	g++ -c main.cpp -std=${STD} ${FLAGS}