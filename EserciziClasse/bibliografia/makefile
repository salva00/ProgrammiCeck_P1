CC=g++
CFLAGS=-std=c++11 -pedantic -Wall
DEPS= Pubblicazioni.h ArticoliConvegni.h ArticoliRiviste.h Libri.h ListaPubblicazioni.h iomanager.h
OBJ= Pubblicazioni.o ArticoliConvegni.o ArticoliRiviste.o Libri.o ListaPubblicazioni.o main.o iomanager.o
EXEC_NAME= bibliografia

 %.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
 $(EXEC_NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
