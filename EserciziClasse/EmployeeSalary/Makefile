#Make file for the Employee Project

CC=g++
CFLAGS=-std=c++11
DEPS=BasePlusCommisionEmployee.h CommissionEmplyee.h Emplouyee.h SalariedEmployee.h
OBJ1=CommissionEmplyee.o SalariedEmployee.o main.o BasePlusCommisionEmployee.o Emplouyee.o
#OBJ2=CommissionEmplyee.o SalariedEmployee.o testDynamic.o BasePlusCommisionEmployee.o Emplouyee.o

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)
all: main #,testDynamic

main: $(OBJ1)
	$(CC) -o $@ $^ $(CFLAGS)

#testDynamic: $(OBJ2)
#	$(CC) -o $ç $^ $(CFLAGS)
